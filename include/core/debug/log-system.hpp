#ifndef _MIA_LOG_SYSTEM_H
#define _MIA_LOG_SYSTEM_H

#include <string>

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

#define MIA_LOG(level, ...) \
    spdlog::default_logger_raw()->log(spdlog::source_loc{__FILE__, __LINE__, SPDLOG_FUNCTION}, level, __VA_ARGS__)

#define MIA_LOG_TRACE(...) MIA_LOG(spdlog::level::trace, __VA_ARGS__)
#define MIA_LOG_DEBUG(...) MIA_LOG(spdlog::level::debug, __VA_ARGS__)
#define MIA_LOG_INFO(...) MIA_LOG(spdlog::level::info, __VA_ARGS__)
#define MIA_LOG_WARN(...) MIA_LOG(spdlog::level::warn, __VA_ARGS__)
#define MIA_LOG_ERROR(...) MIA_LOG(spdlog::level::err, __VA_ARGS__)
#define MIA_LOG_CRITICAL(...) MIA_LOG(spdlog::level::critical, __VA_ARGS__)

namespace mia
{
    void init_logging();
}

#endif