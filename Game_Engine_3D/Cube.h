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
#include <iostream>
using namespace glm;

class Cube
{
public:
	Cube(vec3 position, float sizeX, float sizeY, float sizeZ,int positionV,int texCoordV);
	void setTexture(sf::Texture &t);
	void draw(sf::RenderWindow& window);
	glm::vec3 getPosition();
	void move(uvec3 value);
	bool visibility;
private:
	sf::Texture *texture = nullptr;
	GLuint vao;
	GLuint vertexVBO;
	GLuint indexVBO;
	GLfloat *cube;
	int positionV ;
	int texCoordV;
	unsigned int *indices;
	vec3 position;
	unsigned int drawCount;
	float sizeX;
	float sizeY;
	float sizeZ;
	
};

