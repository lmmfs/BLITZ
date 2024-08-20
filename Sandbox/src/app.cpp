#include <blitz.h>


class Sandbox : public blitz::Application
{

public:
    Sandbox (/* args */);
    ~Sandbox ();
};

Sandbox ::Sandbox (/* args */)
{
}

Sandbox ::~Sandbox ()
{
}


blitz::Application* blitz::createApplication() {
    return new Sandbox();
}