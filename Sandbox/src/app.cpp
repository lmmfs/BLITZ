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


int main() {
    Sandbox* box = new Sandbox();
    box->run();
    delete box;
}