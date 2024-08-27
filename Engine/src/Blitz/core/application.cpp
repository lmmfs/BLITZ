#include "blpch.h"
#include "application.h"

#include "logger/logger.h"
#include "Blitz/events/applicationEvent.h"

#include "Blitz/math/math.h"

namespace blitz {
    Application::Application() {
        //m_Window = Window("Blitz", 960, 540);
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


        while (true)
        {
            /* code */
        }
    }

}