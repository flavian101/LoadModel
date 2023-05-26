#pragma once
#include "libs.h"
struct Vertex
{
	vec3 position;
	vec3 normals;
	vec3 color;
	vec2 texUV;

};
class VBO
{
public :
	GLuint ID;
	VBO(vector<Vertex>& vertices);

	void Bind();
	void Unbind();
	void Delete();
};

