#include "GameMap.h"

void GameMap::initMap(int positionV, int texCoordV, sf::RenderWindow* window)
{
	int start = -525;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			Cube* tmp = new Cube(glm::vec3(start + 70 * i, -10, start + 70 * j),window, 50, 50, 50, positionV, texCoordV);
			Cube* tmp2 = new Cube(glm::vec3(start + 70 * i, 10, start + 70 * j), window, 30, 30, 30, positionV, texCoordV);
			tmp->setTexture(squereTex);
			tmp->visibility = true;
			tmp2->setTexture(moveT);
			tmp2->visibility = false;
			squereList.push_back(*tmp);
			movePoints.push_back(*tmp2);
		}


	}
	ground = new Cube(glm::vec3(0, 0, 0),window, 4000, 10, 4000, positionV, texCoordV);
	ground->setTexture(grasTex);
	ground->visibility = true;
}

GameMap::GameMap(sf::RenderWindow* window,int boardSize, Texture& ground, Texture& squere,Texture& moveT, int positionV, int texCoordV)
{
	this->moveT = moveT;
	this->grasTex = ground;
	this->squereTex = squere;
	size = boardSize;
	initMap(positionV, texCoordV,window);
}

void GameMap::showMap(RenderWindow& window,GLuint program, glm::mat4& viewProj)
{
	for (int i = 0; i < squereList.size(); i++)
	{
		squereList[i].draw(&window,program,viewProj);

	}
	for (int i = 0; i < movePoints.size(); i++)
	{
		movePoints[i].draw(&window,program,viewProj);

	}
	ground->draw(&window, program, viewProj);

}

glm::vec3 GameMap::getPos(int x)
{
	if(x<0||x>size*size-1)
		return glm::vec3(0,0,0);
	glm::vec3 tmp = glm::vec3(squereList[x].getPosition());
	std::cout << tmp.x << " " << tmp.y << " " << tmp.z << std::endl;
	return glm::vec3(squereList[x].getPosition());
}

int GameMap::getSize()
{
	return size;
}

void GameMap::showAllMoves(int num)
{
	for (int i = 0; i < movePoints.size(); i++)
	{
		movePoints[i].visibility = false;
	}
	showOneMove(num);
	showOneMove(num+1);
	showOneMove(num+2);
	showOneMove(num-1);
	showOneMove(num-2);
	showOneMove(num-size*2);
	showOneMove(num-size);
	showOneMove(num-size+1);
	showOneMove(num-size-1);
	showOneMove(num+size);
	showOneMove(num+size+1);
	showOneMove(num+size-1);
	showOneMove(num+size*2);
	//std::cout << std::endl;
}

void GameMap::showOneMove(int num)
{
	//std::cout << num << " ";
	if (num<0 || num>(size*size - 1))
		return;
	movePoints[num].visibility = true;
}
