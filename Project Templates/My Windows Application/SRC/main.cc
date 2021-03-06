#include <Windows.h>
#include "Resource.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPWSTR /*lpCmdLine*/, int /*nCmdShow*/){
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0)) {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}