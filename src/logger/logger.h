#pragma once

#include "spdlog/spdlog.h"

#include <memory>

namespace blitz {
    class Logger
    {
        private:
            static std::shared_ptr<spdlog::logger> m_Logger;
        public:
            static void init();

            inline static std::shared_ptr<spdlog::logger>& getLogger() { return m_Logger; }
    };

    #define BLITZ_LOG_TRACE(...) Logger::getLogger()->trace(__VA_ARGS__)
    #define BLITZ_LOG_INFO(...) Logger::getLogger()->info(__VA_ARGS__)
    #define BLITZ_LOG_WARN(...) Logger::getLogger()->warn(__VA_ARGS__)
    #define BLITZ_LOG_ERROR(...) Logger::getLogger()->error(__VA_ARGS__)
    
}