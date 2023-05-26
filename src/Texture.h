#pragma once
#include "Shader.h"
class Texture
{
public:
	GLuint ID;
	const char* type;
	GLuint unit;
	
	Texture(const char* texImagePath, GLuint slot);
	void texUnit(Shader& shader, const char* uniform, GLuint unit);
	void Bind();
	void Unbind();
	void Delete();

};

