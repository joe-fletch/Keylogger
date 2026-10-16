**README WRITTEN BY AI**

Windows Low-Level Keyboard Logger in C

A minimalist, educational system-wide keyboard hook implemented in pure C using the Windows API. This project is built to explore low-level system hooks, message loops, virtual key translations, and file I/O operations on Windows.
Features

    System-Wide Tracking: Uses WH_KEYBOARD_LL to capture global keystrokes across all open windows.

    Layout-Aware Translation: Leverages MapVirtualKeyExW paired with explicit keyboard layout handles (LoadKeyboardLayoutW) to translate virtual keys into characters.

    Timestamp Logging: Records both the pressed key and the event timestamp.

    File Persistence: Appends logs directly to a local text file (logger.txt) efficiently.

Prerequisites

    Operating System: Windows (7, 8, 10, or 11)

    Compiler: A C compiler supporting Windows libraries (such as GCC via MinGW or MSVC)

Compilation & Building

If you are using GCC (via MinGW) in your terminal, you can compile the project by linking the required Windows user library (-luser32):
Bash

gcc main.c -o keylogger.exe -luser32

To run the compiled executable, simply execute it from your command line:
Bash

./keylogger.exe

Code Overview

    hook_proc: The low-level callback function triggered by Windows whenever a keyboard event occurs. It unpacks the KBDLLHOOKSTRUCT, translates virtual key codes, and dispatches them to the file writer.

    writeToFile: Handles file operations in append mode ("a") to safely store the event stream.

    main: Sets up the global hook using SetWindowsHookExA and spins up a standard Windows message pump (GetMessage, TranslateMessage, DispatchMessage) to keep the hook alive.

Disclaimer

    Educational Purpose Only: This project is intended strictly for educational purposes, portfolio demonstration, and understanding Windows internal messaging and system hooks. Always ensure you have explicit permission before running monitoring tools on any system
