#ifndef _MIA_LOG_SYSTEM_H
#define _MIA_LOG_SYSTEM_H

#include <cstdarg>

namespace mia
{
    void LogInfo(const char* format, ...);
    void LogWarn(const char* format, ...);
    void LogError(const char* format, ...);
}

#endif