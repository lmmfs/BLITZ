#pragma once

#include <glad/glad.h>
#include "../utils/fileUtils.h"
#include "../math/matrices/mat4.h"

namespace blitz {
    class Shader {
        private:
            GLuint m_ShaderID;
            const char* m_VertPath;
            const char* m_FragPath;
        
        public:
            Shader(const char* vertPath, const char* fragPath);
            ~Shader();

            void enable() const;
            void disable() const;

            void setUniform1i(const GLchar* name, int value);
            void setUniform1f(const GLchar* name, float value);
            void setUniform2f(const GLchar* name, const Vec2& vector);
            void setUniform3f(const GLchar* name, const Vec3& vector);
            void setUniform4f(const GLchar* name, const Vec4& vector);
            void setUniformMat4(const GLchar* name, const Mat4& matrix);

            GLuint getShaderID();
        
        private:
            GLuint load();
            GLint getUniformLocation(const GLchar* name);
    };
}