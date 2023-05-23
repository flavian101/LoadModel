#pragma once
#include "libs.h"

void print_ShaderLog(GLuint shader);
void print_ProgramLog(int prog);
bool check_openGLError();


string readShaderSRC(const char* filePath);
string get_file_contents(const char* filename);


GLuint createShaderProgram(const char* vp, const char* fp);

GLuint createShaderProgram(const char* vp, const char* gp, const char* fp);

GLuint createShaderProgram(const char* vp, const char* tCS, const char* tES, const char* fp);

GLuint createShaderProgram(const char* vp, const char* tCS, const char* tES, const char* gp, const char* fp);

GLuint loadCubeMap(const char* mapDir);