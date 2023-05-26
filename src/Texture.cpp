#include "Texture.h"



Texture::Texture(const char* texImagePath, GLuint slot)
{
	//load with SOIL
}

void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit)
{

	////GLuint text0Uni = glGetUniformLocation(shader.ID, uniform);
	//shader.Activate();
	//glUniform1i(text0Uni, unit);
}

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}

