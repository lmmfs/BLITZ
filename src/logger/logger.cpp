#include "logger.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace blitz {
    std::shared_ptr<spdlog::logger> Logger::m_Logger;

    void Logger::init() {
        spdlog::set_pattern("%^[%T] %n %v%$");
        m_Logger = spdlog::stdout_color_mt("BLITZ");
        m_Logger->set_level(spdlog::level::trace);
    }

    
}