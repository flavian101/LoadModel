#pragma once
#include "libs.h"


class IBO
{
	GLuint ID;
	IBO(vector<GLuint>& indices);

	void Bind();
	void Unbind();
	void Delete();
};

