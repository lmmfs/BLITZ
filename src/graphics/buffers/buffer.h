#pragma once

#include <glad/glad.h>

namespace blitz {

    class  Buffer {
        private:
            GLuint m_BufferID;
            GLuint m_ComponentCount;
        public:
            Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
            
            void bind() const;
            void unbind() const;

            inline GLuint getComponentCount() const { return m_ComponentCount; }
            // todo delete this 
            inline  GLuint getID() const { return m_BufferID; }

    };
}