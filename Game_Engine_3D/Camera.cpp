#include "Camera.h"
#include <glm/gtx/string_cast.hpp>
#include <iostream>



Camera::Camera()
{
	Camera(1, 1);
}

Camera::Camera(int width, int height)
{
	rotation = glm::rotate(glm::mat4(1.0f), 0.00f, glm::vec3(0.0f, 1.0f, 0.0f));
	cameraPosition = glm::vec3(  0.f,-200.f,-1000.f);


	resizeWindowProjection(width,height);
}

void Camera::move(glm::vec3 vec)
{
	cameraPosition += vec;
}
void Camera::resizeWindowProjection(int width, int height)
{
	GLfloat ratio = static_cast<float>(width) / height;
	projection = glm::perspective(glm::radians(60.0f), (float)width / (float)height, 0.1f, 3000.0f);
}
void Camera::transformCamera(GLint uniform[], int uniformType, GLuint& program,float time)
{


	

	
	

	glm::mat4 matrix_pos = glm::translate(cameraPosition);

	glm::mat4 transform = matrix_pos * rotation;
	glm::mat4 viewProj = projection * transform;// *glm::translate(glm::vec3(-50, 50, 50));


	
	//Bind the shaders.
	glUseProgram(program);
	const float radius = 10.0f;
	float camX = sin(2) * radius;
	float camZ = cos(time) * radius;
	
	view = projection* transform * glm::lookAt(glm::vec3(camX, 0.0, 0.0), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
	

	//Set the uniforms for the shader to use.
	if (uniform[uniformType] >= 0)
		glUniformMatrix4fv((unsigned int)uniform[uniformType], 1, GL_FALSE, &viewProj[0][0]);



	
	//glUniformMatrix4fv()
}

glm::mat4* Camera::getView()
{
	return &view;
}

void Camera::rotate(float x, float y, float z,float frameTime)
{
	
	glm::mat4 matrix_rotX = glm::rotate(frameTime * x * (3.1415926f / 180.0f), glm::vec3(1.f, 0.f, 0.f));
	glm::mat4 matrix_rotY = glm::rotate(frameTime * y * (3.1415926f / 180.0f), glm::vec3(0.f, 1.f, 0.f));
	glm::mat4 matrix_rotZ = glm::rotate(frameTime * z * (3.1415926f / 180.0f), glm::vec3(0.f, 0.f, 1.f));

	rotation *= matrix_rotX * matrix_rotY * matrix_rotZ;

	//std::cout << glm::to_string(rotation) << std::endl;



	//rotation = glm::rotate(glm::mat4(1.0f), 0.05f, glm::vec3(0.0f, 1.0f, 0.0f)) * rotation;

}
