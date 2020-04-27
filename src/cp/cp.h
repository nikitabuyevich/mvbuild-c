#ifndef CP_H
#define CP_H

#include <stdio.h>
// Included here to avoid debugging nightmares later
// since windows.h must come before stb.h
#include <windows.h>
// Define #define STB_DEFINE in main.c
#include "stb/stb.h"

// Copies the contents from one source file to another.
// Destination file is created if it does not exist.
void cp(char dst[], char src[]);

#endif //CP_H
