#include "window.h"


namespace blitz {

    void resize_window(GLFWwindow* window, int width, int height);
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);


    Window::Window(const char *name, const int& width, const int& height) {
        m_Name = name;
        m_Width = width;
        m_Height = height;

        if (!init()) {
            glfwTerminate();
        }

        for (int i = 0; i < MAX_KEYS; i++) {
            m_Keys[i] = false;
        }

        for (int i = 0; i < MAX_BOTTONS; i++) {
            m_MouseBottons[i] = false;
        }
    }

    Window::~Window() {
        glfwTerminate();
    }

    bool Window::init() {
        if (!glfwInit()) {
            std::cout << "Failed to initialize GLFW" << std::endl;
            return false;
        } else {
            std::cout << "Successfully initialized GLFW" << std::endl;
        }

        // Set GLFW to use OpenGL 3.3 and core profile
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);
        if (!m_Window) {
            std::cout << "Failed to create GLFW window" << std::endl;
            return false;
        }
        
        glfwMakeContextCurrent(m_Window);
        //set a blitz::Window pointer to the GLFWwindow to use in the callbacks
        glfwSetWindowUserPointer(m_Window, this);
        //define callbacks
        glfwSetWindowSizeCallback(m_Window, resize_window);
        glfwSetKeyCallback(m_Window, key_callback);
        glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
        glfwSetCursorPosCallback(m_Window, cursor_position_callback);

        // Load GLAD
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return false;
        }

        return true;
    }

    bool Window::closed() const {
        return glfwWindowShouldClose(m_Window);
    }

    void Window::update() {
        glfwPollEvents();
        //glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
        glfwSwapBuffers(m_Window);
    }

    void Window::clear() const {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    bool Window::isKeyPressed(unsigned int keyCode) const {
        if (keyCode > MAX_KEYS) {
            return false;
        }
        return m_Keys[keyCode];
    }

    void Window::getMousePosition(double& x, double& y) {
        x = mX;
        y = mY;
    }
    
    bool Window::isMouseBottonPressed(unsigned int button) const {
        if (button > MAX_BOTTONS) {
            return false;
        }
        return m_MouseBottons[button];
    }

    void resize_window(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        Window* win = (Window*) glfwGetWindowUserPointer(window);
        win->m_Keys[key] = (action != GLFW_RELEASE);
    }

    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
        Window* win = (Window*) glfwGetWindowUserPointer(window);
        win->m_MouseBottons[button] = (action != GLFW_RELEASE);
    }

    void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
        Window* win = (Window*) glfwGetWindowUserPointer(window);
        win->mX = xpos;
        win->mY = ypos;
    }
}