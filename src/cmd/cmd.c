#include "cmd.h"

char *get_arg_value(const char *name, int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];
        char *argName = stb_sprintf("-%s=", name);
        if (stb_prefix(arg, argName)) {
            return stb_dupreplace(arg, argName, "");
        }
    }
    return NULL;
}

void print_usage(Flag (*fs)[], int len)
{
    const char *appName = "mvbuild"; // TODO: Update to app name
    printf("Usage of %s:\n", appName);
    for (int i = 0; i < len; i++) {
        printf("\t-%s string\n\t\t%s\n", (*fs)[i].name, (*fs)[i].usage);
    }
}

void cmd_free_flags(Flag (*fs)[], int len)
{
    for (int i = 0; i < len; i++) {
        free((*fs)[i].val);
    }
    stb_arr_free(fs);
}

void cmd_parse_str(Flag (*fs)[], int len, int argc, char **argv)
{
    for (int i = 0; i < len; i++) {
        char *argVal = get_arg_value((*fs)[i].name, argc, argv);
        if (argVal == NULL) {
            print_usage(fs, len);
            cmd_free_flags(fs, len);
            exit(1);
        }
        (*fs)[i].val = argVal;
    }
}
