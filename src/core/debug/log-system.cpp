#include "core/debug/log-system.hpp"

namespace mia
{
    void init_logging() {
        spdlog::set_level(spdlog::level::trace);

        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        console_sink->set_level(spdlog::level::trace);

        auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("log/main.log", true);
        file_sink->set_level(spdlog::level::trace);

        std::shared_ptr<spdlog::logger> logger = std::make_shared<spdlog::logger>("root", spdlog::sinks_init_list({console_sink, file_sink}));
        logger->set_level(spdlog::level::trace);

        spdlog::register_logger(logger);
        spdlog::set_default_logger(logger);

        spdlog::set_pattern("%^[%l]%$ [%@] %v");
    }
}
