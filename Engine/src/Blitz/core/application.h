#pragma once

#include "core.h"
#include "Blitz/events/event.h"


namespace blitz {
    class ENGINE_API Application {
    
    private:
        //Window m_Window;
    public:
        Application();
        virtual ~Application();

        void run();

        // To be defined in client side
        Application* createApplication();
    
    };
}
