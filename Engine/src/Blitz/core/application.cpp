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
        std::cout << "inside blitz" << std::endl;

        WindowResizeEvent e(1200, 720);
        //BLITZ_CORE_INFO(e);
        BLITZ_CORE_ERROR("teste");

        while (true)
        {
            /* code */
        }
    }

}