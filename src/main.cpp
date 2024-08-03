#include "graphics/window.h"
#include "graphics/shader.h"
#include "math/math.h"
#include "math/matrices/mat4.h"
#include <spdlog/spdlog.h>

int main() {

    using namespace blitz;

    Window window("Blitz", 800, 600);

    // Set the clear color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    // Print OpenGL version
    std::cout << glGetString(GL_VERSION) << std::endl;

   
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    /*float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    }; */

    float vertices[] = {
        4.0f, 3.0f, 0.0f, // left  
        12.0f, 3.0f, 0.0f, // right 
        4.0f,  6.0f, 0.0f  // top   
    }; 

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 

    //Initi and enable shaders
    Shader shader("../src/shaders/basic.vert","../src/shaders/basic.frag");
    shader.enable();

    Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

    //vec4(1.0f, 0.5f, 0.2f, 1.0f)

    shader.setUniformMat4("pr_matrix", ortho);
    shader.setUniformMat4("ml_matrix", Mat4::translate(Vec3(3,3,0)));

    shader.setUniform2f("lightPos", Vec2(8.0f, 4.5f));
    

    //colour lightPos

    while (!window.closed()) {
        window.clear();

        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
        shader.setUniform4f("colour", Vec4(1.0f, greenValue, 0.2f, 1.0f));

        if (window.isKeyPressed(GLFW_KEY_A)) {
            spdlog::info("Welcome to spdlog!");
            std::cout << "HELLO THERE" << std::endl;
        }
        
        if (window.isMouseBottonPressed(GLFW_MOUSE_BUTTON_1)) {
            std::cout << "BASIC" << std::endl;
        }

        //glUseProgram(shaderProgram);
        // Render the triangle
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.update();
    }

    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    return 0;
}