#include "log-system.h"

#include <cstdio>

// TODO: Re-implement 

void _log_LogWithPrefix(const char* prefix, const char* format, va_list& args);

void mia::LogInfo(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    _log_LogWithPrefix("[Info] ", format, args);

    va_end(args);
}

void mia::LogWarn(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    _log_LogWithPrefix("[Warn] ", format, args);
    
    va_end(args);
}

void mia::LogError(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    _log_LogWithPrefix("[Error] ", format, args);
    
    va_end(args);
}

void _log_LogWithPrefix(const char* prefix, const char* format, va_list& args)
{
    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), format, args);

    printf(prefix);
    printf(buffer);
    printf("\n");
}