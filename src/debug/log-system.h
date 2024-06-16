#ifndef _MIA_LOG_SYSTEM_H
#define _MIA_LOG_SYSTEM_H

#include <cstdarg>

#include "util/singleton.hpp"

namespace mia
{
    class LogManager : public Singleton<LogManager> 
    {
        friend class Singleton<LogManager>;
    public:
        void LogInfo(const char* format, ...);
        void LogWarn(const char* format, ...);
        void LogError(const char* format, ...);

    private:
        void LogWithPrefix(const char* prefix, const char* format, va_list& args);
    };
}

#endif