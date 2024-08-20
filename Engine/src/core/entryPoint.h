#pragma once

#include <iostream>

namespace blitz {
    // This function must be defined in the client application
    extern Application* createApplication();
}

int main(int argc, char** argv) {
    std::cout << "inside blitz 3" << std::endl;
    blitz::Application* app = blitz::createApplication();
    app->run();
    delete app;
}