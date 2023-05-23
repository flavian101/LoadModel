#include "Shader.h"

string readShader(const char* filepath) {
	string content;
	ifstream filestream(filepath, ios::in);
	string line = "";
	while (!filestream.eof())
	{
		getline(filestream, line);
		content.append(line + "\n");
	}
	filestream.close();
	return content;
}
Shader::Shader(const char* vp, const char* fp) //shader Program
{
	GLint verCompiled;
	GLint fragCompiled;
	GLint linked;

	string verShaderStr = readShader(vp);
	string fragShaderStr = readShader(fp);

	const char* vShaderSource = verShaderStr.c_str();
	const char* fShaderSource = fragShaderStr.c_str();

	GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vshader, 1, &vShaderSource, NULL);
	glShaderSource(fshader, 1, &fShaderSource, NULL);

	glCompileShader(vshader);
	checkOpenGLError();
	glGetShaderiv(vshader, GL_COMPILE_STATUS, &verCompiled);
	if (verCompiled != 1)
	{
		cout << " vertex shader compilation failed" << endl;
		PrintShaderLog(vshader);
	}

	glCompileShader(fshader);											//compile fragmentShader
	checkOpenGLError();
	glGetShaderiv(fshader, GL_COMPILE_STATUS, &fragCompiled);
	if (fragCompiled != 1)
	{
		cout << "fragment shader compilation failed" << endl;
		PrintShaderLog(fshader);
	}
	ID = glCreateProgram();
	glAttachShader(ID, vshader);
	glAttachShader(ID, fshader);

	glLinkProgram(ID);
	checkOpenGLError();
	glGetProgramiv(ID, GL_LINK_STATUS, &linked);
	if (linked != 1)
	{
		cout << " linking programVF failed" << endl;
		PrintProgramLog(ID);
	}

}


void Shader::Activate()
{
	glUseProgram(ID);
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}

void Shader::PrintShaderLog(GLuint shader)
{
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
	if (len > 0)
	{
		log = (char*)malloc(len);
		glGetShaderInfoLog(shader, len, &chWrittn, log);
		cout << "shader info Log" << log << endl;
		free(log);
	}

}

void Shader::PrintProgramLog(int prog)
{
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
	if (len > 0)
	{
		log = (char*)malloc(len);
		glGetProgramInfoLog(prog, len, &chWrittn, log);
		cout << " program info log" << log << endl;
		free(log);
	}
}

bool Shader::checkOpenGLError()
{
	bool foundError = false;
	int glErro = glGetError();
	while (glErro != GL_NO_ERROR)
	{
		cout << "OPENGL ERROR" << glErro << endl;
		foundError = true;
		glErro = glGetError();
	}

	return foundError;
}