#include <blitz.h>

class ExampleLayer : public blitz::Layer {
public:
    ExampleLayer () : Layer("Example") {

    }

    ~ExampleLayer() {

    }

    void onUpdate() override {
        BLITZ_INFO("ExampleLayer::Update");
    }

    void onEvent(blitz::Event& event) override {
        BLITZ_TRACE(event);
    }

};

class Sandbox : public blitz::Application {

public:
    Sandbox () {
        pushLayer(new ExampleLayer());
        pushOverlay(new blitz::ImGuiLayer());
    }

    ~Sandbox () {

    }
};


blitz::Application* blitz::createApplication() {
    return new Sandbox();
}