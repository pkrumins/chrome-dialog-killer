#include <windows.h>
#include <cstdio>

int main() {
    while (1) {
        HWND dialog = FindWindow("#32770", "Google Chrome");
        if (dialog) {
            printf("Found dialog: %x\n", dialog);
            HWND dialogItem = NULL;
            while (1) {
                dialogItem = FindWindowEx(dialog, dialogItem, NULL, NULL);
                if (dialogItem == NULL) {
                    break;
                }
                char windowText[255];
                GetWindowText(dialogItem, windowText, 255);
                if (strcmp(windowText, "OK") == 0) {
                    SetActiveWindow(dialog);
                    SendMessage(dialogItem, BM_CLICK, NULL, NULL);
                    break;
                }
            }
        }
        Sleep(1000);
    }
}
