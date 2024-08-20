#include "texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../utils/stb_image.h"
#include "../core/logger/logger.h"

namespace blitz {
    Texture::Texture(const std::string& path) 
        : m_Path(path) {
           m_TextureID = load();
    }

	Texture::~Texture() {
        glDeleteTextures(1, &m_TextureID);
    }

	void Texture::bind() const {
        //glActiveTexture(GL_TEXTURE0 + 1);
        glBindTexture(GL_TEXTURE_2D, m_TextureID);
    }

	void Texture::unbind() const {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    GLuint Texture::load() {
        stbi_set_flip_vertically_on_load(true);
        unsigned char* Imagedata = stbi_load(m_Path.c_str(), &m_Width, &m_Height, &m_NrChannels, 4);

        if(Imagedata == NULL) 
            BLITZ_LOG_ERROR("Failed to load texture: {}", m_Path);

        GLuint result;
        glGenTextures(1, &result);
        glBindTexture(GL_TEXTURE_2D, result);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedata);
        glBindTexture(GL_TEXTURE_2D, 0);

        stbi_image_free(Imagedata);
        return result;
        
        
    }
}