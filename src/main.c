#define WIN32_LEAN_AND_MEAN
#define STB_DEFINE
#define STB_DS_IMPLEMENTATION
#include "cmd/cmd.h"
#include "wnd/wnd.h"
#include "cp/cp.h"

int main(int argc, char *argv[])
{
    Flag flags[] = {
        {.name = "class", .usage = "Process class name to kill. e.g., \"ConsoleWindowClass\""},
        {.name = "src", .usage = "Source to copy contents from. Must be a full path."},
        {.name = "dst", .usage = "Destination to copy contents to. Must be a full path."}
    };
    int flagsLen = sizeof(flags) / sizeof(flags[0]);

//    cmd_parse_str(&flags, flagsLen, argc, argv);
//    printf("lol %s\n", flags[0].val);
////
//    wnd_kill_processes_by_class_name(className);
//    cp(dst, src);
//
//    cmd_free_flags(&flags, flagsLen);
    return 0;
}
