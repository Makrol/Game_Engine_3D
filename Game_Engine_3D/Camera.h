#pragma once
#pragma once
#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/glm.hpp" 
#include "glm/gtx/transform.hpp"
#ifndef GL_SRGB8_ALPHA8
#define GL_SRGB8_ALPHA8 0x8C43

#endif
class Camera
{
private:
	glm::vec3 cameraPosition;
	glm::mat4 projection;
	glm::mat4 rotation;


public:
	Camera();
	Camera(int width,int height);
	void move(glm::vec3 vector);
	void rotate(float x, float y, float z, float frameTime);
	void resizeWindowProjection(int width, int height);
	void transformCamera(GLint uniform[], int uniformType, GLuint& program,float time);
};

