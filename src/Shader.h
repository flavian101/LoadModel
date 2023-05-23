#pragma once
#include "libs.h"

string readShader(const char* filepath);

class Shader
{
public:
	GLuint ID;
	Shader(const char* vp, const char* fp);

	void Activate();
	void Delete();



private:
	void PrintShaderLog(GLuint shader);
	void PrintProgramLog(int prog);
	bool checkOpenGLError();

};

