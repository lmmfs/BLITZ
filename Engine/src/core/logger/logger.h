#pragma once

#include <spdlog/spdlog.h>
#include "../core.h"

#include <memory>

namespace blitz {
    class ENGINE_API Logger
    {
        private:
            static std::shared_ptr<spdlog::logger> m_CoreLogger;
            static std::shared_ptr<spdlog::logger> m_ClientLogger;
        public:
            static void init();

            inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return m_CoreLogger; }
            inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return m_ClientLogger; }
    };

    #define BLITZ_LOG_TRACE(...) Logger::getCoreLogger()->trace(__VA_ARGS__)
    #define BLITZ_LOG_INFO(...) Logger::getCoreLogger()->info(__VA_ARGS__)
    #define BLITZ_LOG_WARN(...) Logger::getCoreLogger()->warn(__VA_ARGS__)
    #define BLITZ_LOG_ERROR(...) Logger::getCoreLogger()->error(__VA_ARGS__)
    
}