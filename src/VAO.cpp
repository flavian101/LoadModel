
#include "VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

void VAO::linkAttributes(VBO& vbo, GLuint layout, GLuint numComponets, GLenum type, GLsizeiptr stride, void* offset)
{
	vbo.Bind();
	glVertexAttribPointer(layout, numComponets, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	vbo.Unbind();
}

void VAO::Bind()
{
	glBindVertexArray(ID);
}

void VAO::Unbind()
{
	glBindVertexArray(0);
}

void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}
