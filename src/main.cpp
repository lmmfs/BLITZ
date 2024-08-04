#include "graphics/window.h"
#include "graphics/shader.h"
#include "math/math.h"
#include "math/matrices/mat4.h"
#include "logger/logger.h"

#include "graphics/buffers/buffer.h"
#include "graphics/buffers/indexBuffer.h"
#include "graphics/buffers/vertexArray.h"

int main() {

    using namespace blitz;

    Logger::init();

    Window window("Blitz", 960, 540);

    // Set the clear color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    // Print OpenGL version

    //todo use logger here
    std::cout << glGetString(GL_VERSION) << std::endl;

#if 0

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
#else
    GLfloat vertices[] = {
        0, 0, 0, 
        0, 3, 0, 
        8, 3, 0,
        8, 0, 0
    }; 

    GLushort indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    GLfloat colorsA[] = {
        1, 1, 1, 1, 
        1, 1, 1, 1, 
        1, 1, 1, 1, 
        1, 1, 1, 1 
    }; 

    GLfloat colorsB[] = {
        1, 0.5f, 0.2f, 1, 
        1, 0.5f, 0.2f, 1, 
        1, 0.5f, 0.2f, 1, 
        1, 0.5f, 0.2f, 1 
    }; 

    VertexArray sprite1, sprite2;
    IndexBuffer ibo(indices, 6);

    sprite1.addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
    sprite1.addBuffer(new Buffer(colorsA, 4 * 4, 4), 1);
    
    sprite2.addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
    sprite2.addBuffer(new Buffer(colorsB, 4 * 4, 4), 1);
#endif

    //Initi and enable shaders
    Shader shader("../src/shaders/basic.vert","../src/shaders/basic.frag");
    shader.enable();

    Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

    shader.setUniformMat4("pr_matrix", ortho);
    shader.setUniformMat4("ml_matrix", Mat4::translate(Vec3(3,3,0)));
    shader.setUniform4f("colour", Vec4(1.0f, 0.5f, 0.2f, 1.0f));

    while (!window.closed()) {
        window.clear();

        double x,y;
        window.getMousePosition(x, y);
        shader.setUniform2f("lightPos", Vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
#if 0
        // Render the triangle
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
#else
        sprite1.bind();
        ibo.bind();

        shader.setUniformMat4("ml_matrix", Mat4::translate(Vec3(0,0,0)));
        glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);

        sprite1.unbind();
        ibo.unbind();

        sprite2.bind();
        ibo.bind();

        shader.setUniformMat4("ml_matrix", Mat4::translate(Vec3(4,3,0)));
        glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);

        sprite2.unbind();
        ibo.unbind();
        
#endif

        window.update();
    }

#if 0
    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
#endif

    return 0;
}