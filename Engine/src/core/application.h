#pragma once

//#include "../graphics/window.h"
#include "core.h"

namespace blitz {
    class ENGINE_API Application {
    
    private:
        //Window m_Window;
    public:
        Application();
        virtual ~Application();

        void run();
    
    };
}