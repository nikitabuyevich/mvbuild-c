#define WIN32_LEAN_AND_MEAN
#define STB_DEFINE
#define STB_DS_IMPLEMENTATION
#include "cmd/cmd.h"
#include "wnd/wnd.h"
#include "cp/cp.h"

int main(int argc, char *argv[])
{
    // Update index of values if order is modified
    Flag flags[] = {
        {.name = "class", .usage = "Process class name to kill. e.g., \"ConsoleWindowClass\""},
        {.name = "src", .usage = "Source to copy contents from. Must be a full path."},
        {.name = "dst", .usage = "Destination to copy contents to. Must be a full path."}
    };
    int flagsLen = sizeof(flags) / sizeof(flags[0]);
    cmd_parse_str(&flags, flagsLen, argc, argv);
    char *class = flags[0].val;
    char *src = flags[1].val;
    char *dst = flags[2].val;

    wnd_kill_processes_by_class_name(class);
    cp(dst, src);

    cmd_free_flags(&flags, flagsLen);
    return 0;
}
