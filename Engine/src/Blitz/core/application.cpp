#include "application.h"
#include <iostream>

#include "logger/logger.h"
#include "Blitz/events/applicationEvent.h"

namespace blitz {
    Application::Application() {
        //m_Window = Window("Blitz", 960, 540);
    }

    Application::~Application() {

    }

    void Application::run() {
        WindowResizeEvent e(1200, 720);
        

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