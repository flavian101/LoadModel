#pragma once
#include "Shader.h"



class Camera
{
public:
	vec3 position;
	vec3 orientation = vec3(0.0f,0.0f,-1.0f);
	vec3 up = vec3(0.0f, 1.0f, 0.0f);
	mat4 cameraMatrix = mat4(1.0f);

	int width;
	int height;

	float yaw = -90.0f;
	float pitch = 0.0f;
	float speed = 0.3f;


	Camera(int width, int height, vec3 postion);
	void updateMatrix(float FOV, float nearPlane, float farPlane);

	void Matrix(Shader& shader, const char* uniform);
	void inputs(GLFWwindow* window);
	void mouse(double xOffset, double yOffset);
	
};

