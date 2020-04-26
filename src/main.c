#define WIN32_LEAN_AND_MEAN
#define STB_DEFINE
#include <stdio.h>
#include "cmd/cmd.h"
#include "wnd/wnd.h"
#include "cp/cp.h"

int main(int argc, char *argv[])
{
    char *className = NULL;
    struct Flag f;
    cmd_parse_str(&className, "class", "Process class name to kill. e.g., \"ConsoleWindowClass\"", argc, argv);
    char *src = NULL;
    cmd_parse_str(&src, "src", "Source to copy contents from. Must be a full path.", argc, argv);
    char *dst = NULL;

    cmd_parse_str(&dst, "dst", "Destination to copy contents to. Must be a full path.", argc, argv);
    wnd_kill_processes_by_class_name(className);
    cp(dst, src);

    free(className);
    free(src);
    free(dst);
    return 0;
}
