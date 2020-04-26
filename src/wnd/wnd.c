#include "wnd.h"

void kill_process(HWND hWnd)
{
    DWORD processID;
    if (GetWindowThreadProcessId(hWnd, &processID)) {
        HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processID);
        TerminateProcess(hProcess, 0);
        CloseHandle(hProcess);
    }
}

BOOL CALLBACK kill_processes_by_class_name(HWND hWnd, LPARAM lCKill)
{
    char *cKill = (char *) lCKill;
    int cLen = (int) strlen(cKill);
    char *cName = malloc(cLen * sizeof(char *));
    GetClassName(hWnd, cName, cLen + 1);
    if (strcmp(cKill, cName) == 0) {
        kill_process(hWnd);
    }
    free(cName);
    return TRUE;
}

void wnd_kill_processes_by_class_name(const char *s)
{
    EnumWindows(kill_processes_by_class_name, (LPARAM) s);
}
