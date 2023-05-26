#pragma once
#include "libs.h"
#include "VBO.h"

class VAO
{
public:
	GLuint ID;
	VAO();

	void linkAttributes(VBO& vbo, GLuint layout, GLuint numComponets, GLenum type, GLsizeiptr stride, void* offset);
	void Bind();
	void Unbind();
	void Delete();
};