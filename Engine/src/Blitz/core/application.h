#pragma once

#include "core.h"
#include "Blitz/events/event.h"
#include "Blitz/core/window.h"


namespace blitz {
    class ENGINE_API Application {
    
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running;

    public:
        Application();
        virtual ~Application();

        void run();

        void onEvent(Event& event);

        // To be defined in client side
        Application* createApplication();
    
    };
}
