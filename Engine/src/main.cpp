#include "graphics/window.h"
#include "graphics/shader.h"
#include "math/math.h"
#include "math/matrices/mat4.h"
#include "logger/logger.h"

#include "graphics/buffers/buffer.h"
#include "graphics/buffers/indexBuffer.h"
#include "graphics/buffers/vertexArray.h"
#include "graphics/texture.h"

int main() {

    using namespace blitz;

    Logger::init();

    Window window("Blitz", 960, 540);

    // Set the clear color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    // Print OpenGL version

    //todo use logger here
    std::cout << glGetString(GL_VERSION) << std::endl;

    GLfloat vertices[] = {
        0, 0, 0, 
        0, 8, 0, 
        8, 8, 0,
        8, 0, 0
    };

    GLfloat texCoords[] = {
        0, 0,  
        0, 1,  
        1, 1, 
        1, 0 
    }; 

    GLushort indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    GLfloat colorsA[] = {
        1, 0, 1, 1, 
        1, 0, 1, 1, 
        1, 0, 1, 1, 
        1, 0, 1, 1 
    }; 

    VertexArray sprite1;
    IndexBuffer ibo(indices, 6);

    sprite1.addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
    sprite1.addBuffer(new Buffer(colorsA, 4 * 4, 4), 1);
    sprite1.addBuffer(new Buffer(texCoords, 2 * 4, 2), 2);
    

    //Initi and enable shaders
    Shader shader("../src/assets/shaders/basic.vert","../src/assets/shaders/basic.frag");
    shader.enable();

    Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

    shader.setUniformMat4("pr_matrix", ortho);
    shader.setUniformMat4("ml_matrix", Mat4::translate(Vec3(3,3,0)));
    shader.setUniform4f("colour", Vec4(1.0f, 0.5f, 0.2f, 1.0f));

    Texture texture("../src/assets/textures/teste.png");

    while (!window.closed()) {
        window.clear();

        double x,y;
        window.getMousePosition(x, y);
        shader.setUniform2f("lightPos", Vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));

        sprite1.bind();
        ibo.bind();
        texture.bind();

        shader.setUniformMat4("ml_matrix", Mat4::translate(Vec3(2,2,0)));
        glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);

        sprite1.unbind();
        ibo.unbind();
        //texture.unbind();

        window.update();
    }

    return 0;
}