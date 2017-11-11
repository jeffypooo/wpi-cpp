//
// Created by Jefferson Jones on 11/10/17.
//
#include <cstdarg>
#include <cstdio>
#include "logger.h"

namespace io {
    void LogV(const char *tag, const char *fmt, ...) {
        char buf[100];
        va_list arg_list;
        va_start(arg_list, fmt);
        vsnprintf(buf, 100, fmt, arg_list);
        va_end(arg_list);
        printf("%s: ", tag);
        printf("%s\n", buf);
    }

    void LogE(const char *tag, const char *fmt, ...) {
        char buf[100];
        va_list arg_list;
        va_start(arg_list, fmt);
        vsnprintf(buf, 100, fmt, arg_list);
        va_end(arg_list);
        fprintf(stderr, "%s: ", tag);
        fprintf(stderr, "%s\n", buf);
    }
}