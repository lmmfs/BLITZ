#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace blitz {

    #define MAX_KEYS 1024
    #define MAX_BOTTONS 32

    class Window {
        private:
            int m_Width;
            int m_Height;
            const char *m_Name;
            bool m_Closed;
            GLFWwindow* m_Window;

            bool m_Keys[MAX_KEYS];
            bool m_MouseBottons[MAX_BOTTONS];
            double mX;
            double mY;

        public:
            Window(const char *name, const int& width, const int& height);
            ~Window();

            bool closed() const;
            void update();
            void clear() const;

            bool isKeyPressed(unsigned int keyCode) const;
            bool isMouseBottonPressed(unsigned int keyCode) const; 

        private:
            bool init();
            friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
            friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
            friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
        };
}