#include "blpch.h"
#include "application.h"

#include "logger/logger.h"
#include "Blitz/events/applicationEvent.h"

#include "Blitz/math/math.h"


#include <GLFW/glfw3.h>

namespace blitz {
    Application::Application() {
        m_Window = std::unique_ptr<Window>(new Window("Blitz", 960, 540));
        m_Running = true;
    }

    Application::~Application() {

    }

    void Application::run() {
        WindowResizeEvent e(1200, 720);

        Vec2 v(2.0f);
        

        if (e.hasCategory(EventCategoryApplication)) {
            BLITZ_INFO(e);
        }

        if (e.hasCategory(EventCategoryKeyboard)) {
            BLITZ_INFO(e);
        }


        while (m_Running)
        {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->update();
        }
    }

}