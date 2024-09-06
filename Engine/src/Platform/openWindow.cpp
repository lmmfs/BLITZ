#include "blpch.h"
#include "openWindow.h"
#include "Blitz/core/logger/logger.h"


namespace blitz {

    void resize_window(GLFWwindow* window, int width, int height);
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);


    Window* Window::create(const WindowProps& props) {
        return new OpenWindow(props);
    }

    OpenWindow::OpenWindow(const WindowProps& props) {
        init(props);
    }

    OpenWindow::~OpenWindow() {
        shutdown();
        glfwTerminate();
    }

    void OpenWindow::init(const WindowProps& props) {
        m_Data.title = props.title;
        m_Data.width = props.width;
        m_Data.height = props.height;

        BLITZ_CORE_INFO("Creating window {0} ({1}, {2})", m_Data.title, m_Data.width, m_Data.height);

        if (!glfwInit()) {
            BLITZ_CORE_ERROR("Failed to initialize GLFW");
            return;
        } else {
            BLITZ_CORE_INFO("Successfully initialized GLFW");
        }

        // Set GLFW to use OpenGL 3.3 and core profile
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_Window = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.title.c_str(), NULL, NULL);
        if (!m_Window) {
            std::cout << "Failed to create GLFW window" << std::endl;
            return;
        }
        
        glfwMakeContextCurrent(m_Window);
        //set a blitz::Window pointer to the GLFWwindow to use in the callbacks
        glfwSetWindowUserPointer(m_Window, &m_Data);
        /*define callbacks
        glfwSetWindowSizeCallback(m_Window, resize_window);
        glfwSetKeyCallback(m_Window, key_callback);
        glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
        glfwSetCursorPosCallback(m_Window, cursor_position_callback);
        */

       setVSync(true);

        // Load GLAD
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            BLITZ_CORE_ERROR("Failed to initialize GLAD");
            return;
        }
    }

    void OpenWindow::shutdown() {
        glfwDestroyWindow(m_Window);
    }

    bool OpenWindow::closed() const {
        return glfwWindowShouldClose(m_Window);
    }

    void OpenWindow::onUpdate() {
        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            BLITZ_CORE_ERROR("OPENGL ERROR: {}", error);
        }

        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void OpenWindow::setVSync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }
			
        m_Data.vSync = enabled;
    }
	
    bool OpenWindow::isVSync() const {
        return m_Data.vSync;
    }

    void OpenWindow::clear() const {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}