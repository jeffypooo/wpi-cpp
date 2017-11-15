//
// Created by Jefferson Jones on 11/13/17.
//

#ifndef WPI_CPP_CLI_ARGS_H
#define WPI_CPP_CLI_ARGS_H

#include <cstring>
#include <string>

struct CLIArgs {
    int argc;
    char **argv;

    CLIArgs(int argc, char **argv) : argc(argc), argv(argv) {}
};

bool HaveFlag(const char *flag, const CLIArgs &args) {
    if (args.argc <= 1) return false;
    for (int i = 1; i < args.argc; ++i) {
        if (strcmp(flag, args.argv[i]) == 0) {
            return true;
        }
    }
    return false;

}

std::string ArgForFlag(const char *flag, const CLIArgs &args) {
    if (!HaveFlag(flag, args) || args.argc <= 2) return "";
    for (int i = 1; i < args.argc; i++) {
        if (strcmp(flag, args.argv[i]) == 0) {
            return std::string(args.argv[i + 1]);
        }
    }
}


#endif //WPI_CPP_CLI_ARGS_H
