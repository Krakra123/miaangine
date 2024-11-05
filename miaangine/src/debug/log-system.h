#ifndef _MIA_LOG_SYSTEM_H
#define _MIA_LOG_SYSTEM_H

#include <cstdarg>

#include "util/singleton.hpp"

namespace mia
{
    class LogManager 
    {
    public:
        // Block constructor
        LogManager() = delete;

        static void LogInfo(const char* format, ...);
        static void LogWarn(const char* format, ...);
        static void LogError(const char* format, ...);

        static void LogWithPrefix(const char* prefix, const char* format, va_list& args);
    };
}

#endif