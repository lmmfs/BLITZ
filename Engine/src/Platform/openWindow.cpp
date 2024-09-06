#include "blpch.h"
#include "openWindow.h"

#include "Blitz/events/applicationEvent.h"
#include "Blitz/events/keyEvent.h"
#include "Blitz/events/mouseEvent.h"

namespace blitz {

    static void GLFWErrorCallback(int error, const char* description) {
		BLITZ_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

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
        glfwSetErrorCallback(GLFWErrorCallback);

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

        setVSync(true);

        // Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			WindowResizeEvent event(width, height);
			data.eventCallback(event);
		});

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.eventCallback(event);
		});

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch(action) {
                case GLFW_PRESS: {
                    KeyPressedEvent event(key, 0);
                    data.eventCallback(event);
                    break;
                }
                case GLFW_RELEASE:{
                    KeyReleasedEvent event(key);
                    data.eventCallback(event);
                    break;
                }
                case GLFW_REPEAT:{
                    KeyPressedEvent event(key, 1);
                    data.eventCallback(event);
                    break;
                }
            }
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            
            switch (action) {
                case GLFW_PRESS: {
                    MouseButtonPressedEvent event(button);
                    data.eventCallback(event);
                    break;
                }
                case GLFW_RELEASE:{
                    MouseButtonReleasedEvent event(button);
                    data.eventCallback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float)xoffset, (float)yoffset);
            data.eventCallback(event);
        });

        
        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MousedMovedEvent event((float)xpos, (float)ypos);
            data.eventCallback(event);
        });

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