#include "cp.h"

int cp(char dst[], char src[])
{
    FILE *rBuf, *wBuf;
    if (fopen_s(&rBuf, src, "r") != 0) {
        return -1;
    }
    if (fopen_s(&wBuf, dst, "w") != 0) {
        fclose(rBuf);
        return -2;
    }
    int c;
    while ((c = fgetc(rBuf)) != EOF) {
        fputc(c, wBuf);
    }
    fclose(rBuf);
    fclose(wBuf);
    return 0;
}