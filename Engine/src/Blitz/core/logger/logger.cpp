#include "blpch.h"
#include "logger.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace blitz {
    
    std::shared_ptr<spdlog::logger> Logger::m_CoreLogger;
    std::shared_ptr<spdlog::logger> Logger::m_ClientLogger;

    void Logger::init() {
        spdlog::set_pattern("%^[%T] %n %v%$");
        
        m_CoreLogger = spdlog::stdout_color_mt("BLITZ");
        m_CoreLogger->set_level(spdlog::level::trace);

        m_ClientLogger = spdlog::stdout_color_mt("APP");
        m_ClientLogger->set_level(spdlog::level::trace);
    }

}