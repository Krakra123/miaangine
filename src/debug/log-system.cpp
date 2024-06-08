#include "log-system.h"

#include <cstdio>

// TODO: Re-implement 

void __LogWithPrefix(const char* prefix, const char* format, va_list& args);

void mia::LogInfo(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    __LogWithPrefix("[Info] ", format, args);

    va_end(args);
}

void mia::LogWarn(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    __LogWithPrefix("[Warn] ", format, args);
    
    va_end(args);
}

void mia::LogError(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    __LogWithPrefix("[Error] ", format, args);
    
    va_end(args);
}

void __LogWithPrefix(const char* prefix, const char* format, va_list& args)
{
    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), format, args);

    printf(prefix);
    printf(buffer);
    printf("\n");
}