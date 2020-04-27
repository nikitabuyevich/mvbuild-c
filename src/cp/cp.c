#include "cp.h"

void normalize_filename(char *fn)
{
    stb_replaceinplace(fn, "\\", "/");
}

void cp(char dst[], char src[])
{
    normalize_filename(dst);
    normalize_filename(src);
    size_t srcLen;
    void *srcData = stb_file(src, &srcLen);
    stb_filewrite(dst, srcData, srcLen);
    free(srcData);
}