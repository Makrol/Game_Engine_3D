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
#include "Camera.h"
#include <fstream>
#include <sstream>
#include <list>

using namespace sf;
#include "Cube.h"
class Enemy
{
private:
	Cube* body;
	float sizeX;
	float sizeY;
	float sizeZ;
	int positionV;
	int texCoordV;
	Texture enemyTex;


public:
	int posIndex;
	int lockIndex = -1;
	Enemy(Texture& pTex, sf::RenderWindow* window, vec3 position, float sizeX, float sizeY, float sizeZ, int positionV, int texCoordV);
	void update();
	void move(sf::RenderWindow* window, vec3 value, int posIndex, int boardSize);
	void render(RenderWindow* window, GLuint program, glm::mat4& viewProj);
};
