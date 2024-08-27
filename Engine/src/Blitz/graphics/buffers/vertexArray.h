#pragma once

#include <glad/glad.h>

#include "buffer.h"

namespace blitz {
    class VertexArray {        
        private:
            GLuint m_ArrayID;
            std::vector<Buffer*> m_Buffers;
        public:
            VertexArray();
            ~VertexArray();

            void addBuffer(Buffer* buffer, GLuint index);
            
            void bind() const;
            void unbind() const;
    };

}