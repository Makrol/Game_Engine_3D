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

class GameMap
{
private:
	Cube* ground;
	std::vector<Cube> squereList;
	std::vector<Cube> movePoints;
	sf::Texture grasTex;
	sf::Texture squereTex;
	sf::Texture moveT;
	int size;
	void initMap(int positionV, int texCoordV, sf::RenderWindow* window);
public:
	GameMap(sf::RenderWindow* window,int boardSize, Texture &ground, Texture &squere,Texture & moveT, int positionV, int texCoordV);
	void showMap(RenderWindow &window, GLuint program, glm::mat4& viewProj);
	glm::vec3 getPos(int x);
	int getSize();
	void showAllMoves(int num);
	void showOneMove(int num);
};

