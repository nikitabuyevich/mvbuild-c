#ifndef MVBUILD_WND_H
#define MVBUILD_WND_H

#include <stdio.h>
#include <windows.h>

// Kill any running processes that match class name s.
void wnd_kill_processes_by_class_name(const char *s);

#endif //MVBUILD_WND_H
