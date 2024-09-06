#pragma once

#include "Blitz/events/event.h"
#include "Blitz/core/core.h"


namespace blitz {

    struct WindowProps {

		std::string title;
		unsigned int width;
		unsigned int height;

        bool vSync;

		WindowProps(const std::string& title = "Blitz Engine", 
                uint32_t width = 1600, uint32_t height = 900)
			: title(title), width(width), height(height) {}
	};

    class ENGINE_API Window {   
        public:
            using EventCallbackFn = std::function<void(Event&)>;

            virtual ~Window() = default;

            virtual void onUpdate() = 0;

            virtual unsigned int getWidth() const = 0;
            virtual unsigned int getHeight() const = 0;

            // Window attributes
            virtual void setEventCallback(const EventCallbackFn& callback) = 0;
            virtual void setVSync(bool enabled) = 0;
            virtual bool isVSync() const = 0;

            static Window* create(const WindowProps& props = WindowProps());
    };
}