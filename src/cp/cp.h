#ifndef CP_H
#define CP_H

#include <stdio.h>

// cp copies the contents from one source file to another.
// Returns -1 if unable to open src file.
// Returns -2 if unable to write to dst file.
// Returns 0 on successful copy.
int cp(char dst[], char src[]);

#endif //CP_H
