#pragma once

#include <iostream>

namespace blitz {
    // This function must be defined in the client application
    extern Application* createApplication();
}

int main(int argc, char** argv) {
    blitz::Logger::init();
    BLITZ_CORE_INFO("says hell");


    blitz::Application* app = blitz::createApplication();
    app->run();
    delete app;
}
