#pragma once

#include <iostream>

namespace blitz {
    // This function must be defined in the client application
    extern Application* createApplication();
}

int main(int argc, char** argv) {
    blitz::Logger::init();
    //BLITZ_LOG_INFO("inside blitz 3");
    BLITZ_CORE_INFO("inside blitz EP");
    BLITZ_WARN("inside blitz EP");


    blitz::Application* app = blitz::createApplication();
    app->run();
    delete app;
}