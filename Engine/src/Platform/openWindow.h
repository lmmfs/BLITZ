#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Blitz/core/window.h"
#include "Blitz/events/event.h"


namespace blitz {
    
    class OpenWindow : public Window {
        private:
            struct WindowData {
                std::string title;
                unsigned int width;
                unsigned int height;

                bool vSync;

                EventCallbackFn EventCallback;
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
		    void setEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		    void setVSync(bool enabled) override;
		    bool isVSync() const override;

        private:
            virtual void init(const WindowProps& props);
		    virtual void shutdown();
        };
}