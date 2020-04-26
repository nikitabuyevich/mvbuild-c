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

void print_usage(const char *name, const char *usage)
{
    const char *appName = "mvbuild"; // TODO: Update to app name
    printf("Usage of %s:\n\t-%s string\n\t\t%s", appName, name, usage);
}

void cmd_parse_str(char **val, const char *name, const char *usage, int argc, char **argv)
{
    *val = get_arg_value(name, argc, argv);
    if (*val == NULL) {
        print_usage(name, usage);
        free(*val);
        exit(1);
    }
}
