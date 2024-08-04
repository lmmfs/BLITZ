#include "shader.h"
#include "../logger/logger.h"


namespace blitz {
    Shader::Shader(const char* vertPath, const char* fragPath) 
    : m_VertPath(vertPath), m_FragPath(fragPath) {
        m_ShaderID = load();
    }

    Shader::~Shader() {
        glDeleteProgram(m_ShaderID);
    }

    GLuint Shader::load() {
        GLuint shaderProgram = glCreateProgram();
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

        std::string vertSourceString = FileUtils::read_file(m_VertPath);
        std::string fragSourceString = FileUtils::read_file(m_FragPath);
        
        const char* vertSource = vertSourceString.c_str();
        const char* fragSource = fragSourceString.c_str();

        glShaderSource(vertexShader, 1, &vertSource, NULL);
        glCompileShader(vertexShader);

        GLint result;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
        if (!result) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            BLITZ_LOG_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED {}", infoLog);
            glDeleteShader(vertexShader);
        }
        
        glShaderSource(fragmentShader, 1, &fragSource, NULL);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
        if (!result) {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            BLITZ_LOG_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED {}", infoLog);
            glDeleteShader(fragmentShader);
        }

        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);

        glLinkProgram(shaderProgram);
        glValidateProgram(shaderProgram);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return shaderProgram;
    }

    void Shader::enable() const {
        glUseProgram(m_ShaderID);
    }

    void Shader::disable() const {
        glUseProgram(0);
    }

    void Shader::setUniform1i(const GLchar* name, int value) {
        glUniform1i(getUniformLocation(name), value);
    }

    void Shader::setUniform1f(const GLchar* name, float value) {
        glUniform1f(getUniformLocation(name), value);
    }
    
    void Shader::setUniform2f(const GLchar* name, const Vec2& vector) {
        glUniform2f(getUniformLocation(name), vector.x, vector.y);
    }
    
    void Shader::setUniform3f(const GLchar* name, const Vec3& vector) {
        glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
    }
    
    void Shader::setUniform4f(const GLchar* name, const Vec4& vector) {
        glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
    }
    
    void Shader::setUniformMat4(const GLchar* name, const Mat4& matrix) {
        glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
    }

    GLuint Shader::getShaderID() {
        return m_ShaderID;
    }

    GLint Shader::getUniformLocation(const GLchar* name) {
        return glGetUniformLocation(m_ShaderID, name);
    }
}
