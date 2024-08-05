#include "texture.h"
#include <iostream>
#include "../logger/logger.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace blitz {

	Texture::Texture() {

	}

	Texture::Texture(const std::string fileName) {
		glGenTextures(1, &m_texture_id);
		glBindTexture(GL_TEXTURE_2D, m_texture_id);
		
		int width, height, nrChannels;
		unsigned char* Imagedata = stbi_load(fileName.c_str(), &width, &height, &nrChannels, 4);
		if(Imagedata == NULL)
            BLITZ_LOG_ERROR("Failed to load texture: {}", fileName);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Imagedata);
		
		stbi_image_free(Imagedata);
	}


	Texture::~Texture() {
		glDeleteTextures(1, &m_texture_id);
	}

	void Texture::Bind(unsigned int unit){
		assert(unit >= 0 && unit <= 31);
		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(GL_TEXTURE_2D, m_texture_id);

	}
    
	Texture* Texture::parseTexture(const std::string fileName)
	{
		Texture* t = new Texture(fileName);
		return t;
	}
}