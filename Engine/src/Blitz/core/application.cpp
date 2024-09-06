#include "blpch.h"
#include "application.h"

#include "logger/logger.h"
#include "Blitz/events/applicationEvent.h"

#include "Blitz/math/math.h"


#include <GLFW/glfw3.h>

namespace blitz {
    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::create());
        m_Running = true;
    }

    Application::~Application() {

    }

    void Application::run() {

        while (m_Running)
        {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->onUpdate();
        }
    }

}