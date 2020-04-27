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

// Flag is used to parse a cmd from the given const char ptr name.
// The char ptr val is malloced so it must be freed after use.
typedef struct Flag
{
    // Must be freed after use.
    char *val;
    // Name to parse out.
    // If the passed in arg is -foo=bar
    // the name must be foo to get bar as a value.
    const char *name;
    // Display usage about a flag.
    const char *usage;
} Flag;

// Free the flag structure and underlying data.
void cmd_free_flags(Flag (*fs)[], int len);
// Parse a given array of flags.
void cmd_parse_str(Flag (*fs)[], int len, int argc, char **argv);

#endif //CMD_H
