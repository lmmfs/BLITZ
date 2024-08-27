#pragma once

#include <glad/glad.h>

namespace blitz {
	class Texture {
	private:
		GLuint 	m_TextureID;
		int m_Width;
		int m_Height;
		int m_NrChannels;
		std::string m_Path;

	public:
		Texture(const std::string& path);
		~Texture();

		void bind() const;
		void unbind() const;

		//static Texture* parseTexture(const std::string fileName);

		inline const int getWidth() const { return m_Width; }
		inline const int getHeight() const { return m_Height; }
		inline const int getNrChannels() const { return m_NrChannels; }
	private:
		GLuint load();
	};

	
}