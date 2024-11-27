#include "core/debug/log-system.hpp"

#include <cstdio>

// TODO: Re-implement 

namespace mia
{
    void LogManager::LogInfo(const char* format, ...)
    {
        va_list args;
        va_start(args, format);

        LogWithPrefix("[Info] ", format, args);

        va_end(args);
    }

    void LogManager::LogWarn(const char* format, ...)
    {
        va_list args;
        va_start(args, format);

        LogWithPrefix("[Warn] ", format, args);
        
        va_end(args);
    }

    void LogManager::LogError(const char* format, ...)
    {
        va_list args;
        va_start(args, format);

        LogWithPrefix("[Error] ", format, args);
        
        va_end(args);
    }

    void LogManager::LogWithPrefix(const char* prefix, const char* format, va_list& args)
    {
        char buffer[256];
        vsnprintf(buffer, sizeof(buffer), format, args);

        printf(prefix);
        printf(buffer);
        printf("\n");
    }
}
