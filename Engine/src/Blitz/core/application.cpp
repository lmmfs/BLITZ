#include "blpch.h"
#include "application.h"

#include "Blitz/math/math.h"


#include <GLFW/glfw3.h>

namespace blitz {

#define  BIND_EVENT_FUNC(x) std::bind(&x, this, std::placeholders::_1)

    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::create());
        m_Window->setEventCallback(BIND_EVENT_FUNC(Application::onEvent));
        m_Running = true;
    }

    Application::~Application() {

    }

    void Application::run() {

        while (m_Running) {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            //foward layer update
            for (Layer* layer: m_LayerStack) {
                layer->onUpdate();
            }

            m_Window->onUpdate();
        }
    }

    void Application::pushLayer(Layer* layer) {
        m_LayerStack.pushLayer(layer);
    }

    void Application::pushOverlay(Layer* layer) {
        m_LayerStack.pushOverlay(layer);
    }

    void Application::onEvent(Event& event) {
        EventDispatcher dispatcher(event);
        dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(Application::onWindowClose));

        BLITZ_CORE_INFO("Event: {0}", event);

        //backward layer event handleling
        for (auto layer = m_LayerStack.end(); layer != m_LayerStack.begin(); ) {
            (*--layer)->onEvent(event);
            if (event.m_Handled) {
                break;
            }
        }
    }

    bool Application::onWindowClose(WindowCloseEvent& e) {
        m_Running = false;
        return true;
    }
}