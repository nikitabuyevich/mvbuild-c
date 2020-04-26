#ifndef CMD_H
#define CMD_H

#include <stdio.h>
#include <stdlib.h>

// Included here to avoid debugging nightmares later
// since windows.h must come before stb.h
#include <windows.h>
// Define #define STB_DEFINE in main.c
#include "stb/stb.h"
#include "stb/stb_ds.h"

typedef struct Flag
{
    char *val; // needs to be freed
    const char *name;
    const char *usage;
} Flag;

void cmd_free_flags(Flag (*fs)[], int len);
void cmd_parse_str(Flag (*fs)[], int len, int argc, char **argv);

#endif //CMD_H
