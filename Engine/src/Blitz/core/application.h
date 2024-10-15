#pragma once

#include "core.h"
#include "Blitz/events/event.h"
#include "Blitz/core/window.h"
#include "Blitz/events/applicationEvent.h"
#include "Blitz/layers/layerStack.h"


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

        void pushLayer(Layer* layer);
        void pushOverlay(Layer* layer);

        // To be defined in client side
        Application* createApplication();

        inline Window& getWindow() { return *m_Window; }
        inline static Application& getInstance() { return *s_Instance; }
    
    private:
        bool onWindowClose(WindowCloseEvent& e);
        LayerStack m_LayerStack;

        static Application* s_Instance;
    
    };
    
}
