#pragma once

#include "Blitz/core/window.h"
#include <GLFW/glfw3.h>

namespace blitz {
    //Window class that uses OpenGl
    class OpenWindow : public Window {
        private:
            struct WindowData {
                std::string title;
                unsigned int width;
                unsigned int height;

                bool vSync;

                EventCallbackFn eventCallback;
		    };

            WindowData m_Data;
            GLFWwindow* m_Window;

        public:
            OpenWindow(const WindowProps& props);
            ~OpenWindow();

            inline unsigned int getWidth() const override { return m_Data.width; }
            inline unsigned int getHeight() const override { return m_Data.height; }

            bool closed() const;
            void clear() const;

            void onUpdate() override;

            // Window attributes
		    void setEventCallback(const EventCallbackFn& callback) override { m_Data.eventCallback = callback; }
		    void setVSync(bool enabled) override;
		    bool isVSync() const override;

        private:
            virtual void init(const WindowProps& props);
		    virtual void shutdown();
        };
}