#ifndef CMD_H
#define CMD_H

#include <stdio.h>
#include <stdlib.h>

// Included here to avoid debugging nightmares later
// since windows.h must come before stb.h
#include <windows.h>
// Define #define STB_DEFINE in main.c
#include "stb/stb.h"

struct Flag
{
    char **val;
    const char *name;
    const char *usage;
};

void cmd_parse_str(char **val, const char *name, const char *usage, int argc, char **argv);

#endif //CMD_H
