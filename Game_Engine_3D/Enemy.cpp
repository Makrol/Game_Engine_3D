#include "Enemy.h"

Enemy::Enemy(Texture& pTex, sf::RenderWindow* window, vec3 position, float sizeX, float sizeY, float sizeZ, int positionV, int texCoordV)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->sizeZ = sizeZ;
	this->positionV = positionV;
	this->texCoordV = texCoordV;
	enemyTex = pTex;
	body = new Cube(position, window, sizeX, sizeY, sizeZ, positionV, texCoordV);
	body->setTexture(pTex);
	body->visibility = true;
}

void Enemy::update()
{
}

void Enemy::move(sf::RenderWindow* window, vec3 value, int posIndex, int boardSize)
{
	body->move(value, window);
	std::cout << "test2:" << value.x << " " << value.y << " " << value.z << std::endl;
	//body = new Cube(value,window, sizeX, sizeY, sizeZ, positionV, texCoordV);
	body->setTexture(enemyTex);
	this->posIndex = posIndex;
}

void Enemy::render(RenderWindow* window, GLuint program, glm::mat4& viewProj)
{
		body->draw(window, program, viewProj);
}
