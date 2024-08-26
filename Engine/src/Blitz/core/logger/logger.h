#pragma once

#include <spdlog/spdlog.h>
#include "Blitz/core/core.h"

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

    //Core Logger Macros
    #define BLITZ_CORE_TRACE(...) ::blitz::Logger::getCoreLogger()->trace(__VA_ARGS__)
    #define BLITZ_CORE_INFO(...) ::blitz::Logger::getCoreLogger()->info(__VA_ARGS__)
    #define BLITZ_CORE_WARN(...) ::blitz::Logger::getCoreLogger()->warn(__VA_ARGS__)
    #define BLITZ_CORE_ERROR(...) ::blitz::Logger::getCoreLogger()->error(__VA_ARGS__)

    //Client Logger Macros
    #define BLITZ_TRACE(...) ::blitz::Logger::getClientLogger()->trace(__VA_ARGS__)
    #define BLITZ_INFO(...) ::blitz::Logger::getClientLogger()->info(__VA_ARGS__)
    #define BLITZ_WARN(...) ::blitz::Logger::getClientLogger()->warn(__VA_ARGS__)
    #define BLITZ_ERROR(...) ::blitz::Logger::getClientLogger()->error(__VA_ARGS__)
    
}