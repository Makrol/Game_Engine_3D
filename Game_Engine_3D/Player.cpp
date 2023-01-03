#include "Player.h"

Player::Player(Texture &pTex, vec3 position, float sizeX, float sizeY, float sizeZ, int positionV, int texCoordV)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->sizeZ = sizeZ;
	this->positionV = positionV;
	this->texCoordV = texCoordV;
	playerTex = pTex;
	body = new Cube( position,  sizeX,  sizeY,  sizeZ,  positionV,  texCoordV);
	body->setTexture(pTex);
}

void Player::update()
{
}

void Player::move(vec3 value,int posIndex,int boardSize)
{
	if (posIndex<0 || posIndex>(boardSize * boardSize - 1))
		return;
	if (posIndex % boardSize == 0)
		return;
	if ((posIndex+1) % boardSize == 0)
		return;
	if (lockIndex != -1)
	{
		if (posIndex == lockIndex + 1 || posIndex == lockIndex - 1 || posIndex == lockIndex + boardSize || posIndex == lockIndex - boardSize
			|| posIndex == lockIndex
			|| posIndex == lockIndex + 2 || posIndex == lockIndex - 2 || posIndex == lockIndex + boardSize*2 || posIndex == lockIndex - boardSize*2
			|| posIndex == lockIndex +1 +boardSize|| posIndex == lockIndex - 1 + boardSize ||
			posIndex == lockIndex + 1 - boardSize || posIndex == lockIndex - 1 - boardSize)
		{
			//body->move(value);
			body = new Cube(value, sizeX, sizeY, sizeZ, positionV, texCoordV);
			body->setTexture(playerTex);
			this->posIndex = posIndex;
		}
		return;
	}

	//body->move(value);
	body = new Cube(value, sizeX, sizeY, sizeZ, positionV, texCoordV);
	body->setTexture(playerTex);
	this->posIndex = posIndex;
}

void Player::render(RenderWindow& window)
{
	body->draw(window);
}
