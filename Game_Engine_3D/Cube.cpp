/*#include "Cube.h"

Cube::Cube(vec3 position, float sizeX, float sizeY, float sizeZ, int positionV, int texCoordV)
{
	this->position = position;
	this->positionV = positionV;
	this->texCoordV = texCoordV;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->sizeZ = sizeZ;
	visibility = true;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	cube = new GLfloat[120];
	
	cube[0] = position.x - ((float)1 / 2) * sizeX;
	cube[1] = position.y - ((float)1 / 2) * sizeY;
	cube[2] = position.z - ((float)1 / 2) * sizeZ;
	cube[3] = 1;
	cube[4] = 0;

	cube[5] = position.x + ((float)1 / 2) * sizeX;
	cube[6] = position.y - ((float)1 / 2) * sizeY;
	cube[7] = position.z - ((float)1 / 2) * sizeZ;
	cube[8] = 1;
	cube[9] = 0;

	cube[10] = position.x + ((float)1 / 2) * sizeX;
	cube[11] = position.y + ((float)1 / 2) * sizeY;
	cube[12] = position.z - ((float)1 / 2) * sizeZ;
	cube[13] = 1;
	cube[14] = 1;

	cube[15] = position.x - ((float)1 / 2) * sizeX;
	cube[16] = position.y + ((float)1 / 2) * sizeY;
	cube[17] = position.z - ((float)1 / 2) * sizeZ;
	cube[18] = 0;
	cube[19] = 1;

	cube[20] = position.x + ((float)1 / 2) * sizeX;
	cube[21] = position.y + ((float)1 / 2) * sizeY;
	cube[22] = position.z - ((float)1 / 2) * sizeZ;
	cube[23] = 1;
	cube[24] = 1;

	cube[25] = position.x + ((float)1 / 2) * sizeX;
	cube[26] = position.y + ((float)1 / 2) * sizeY;
	cube[27] = position.z + ((float)1 / 2) * sizeZ;
	cube[28] = 0;
	cube[29] = 1;

	cube[30] = position.x + ((float)1 / 2) * sizeX;
	cube[31] = position.y - ((float)1 / 2) * sizeY;
	cube[32] = position.z + ((float)1 / 2) * sizeZ;
	cube[33] = 0;
	cube[34] = 0;

	cube[35] = position.x + ((float)1 / 2) * sizeX;
	cube[36] = position.y - ((float)1 / 2) * sizeY;
	cube[37] = position.z - ((float)1 / 2) * sizeZ;
	cube[38] = 1;
	cube[39] = 0;

	cube[40] = position.x - ((float)1 / 2) * sizeX;
	cube[41] = position.y - ((float)1 / 2) * sizeY;
	cube[42] = position.z + ((float)1 / 2) * sizeZ;
	cube[43] = 0;
	cube[44] = 0;

	cube[45] = position.x + ((float)1 / 2) * sizeX;
	cube[46] = position.y - ((float)1 / 2) * sizeY;
	cube[47] = position.z + ((float)1 / 2) * sizeZ;
	cube[48] = 1;
	cube[49] = 0;

	cube[50] = position.x + ((float)1 / 2) * sizeX;
	cube[51] = position.y + ((float)1 / 2) * sizeY;
	cube[52] = position.z + ((float)1 / 2) * sizeZ;
	cube[53] = 1;
	cube[54] = 1;

	cube[55] = position.x - ((float)1 / 2) * sizeX;
	cube[56] = position.y + ((float)1 / 2) * sizeY;
	cube[57] = position.z + ((float)1 / 2) * sizeZ;
	cube[58] = 0;
	cube[59] = 1;

	cube[60] = position.x - ((float)1 / 2) * sizeX;
	cube[61] = position.y - ((float)1 / 2) * sizeY;
	cube[62] = position.z + ((float)1 / 2) * sizeZ;
	cube[63] = 0;
	cube[64] = 0;

	cube[65] = position.x - ((float)1 / 2) * sizeX;
	cube[66] = position.y - ((float)1 / 2) * sizeY;
	cube[67] = position.z - ((float)1 / 2) * sizeZ;
	cube[68] = 1;
	cube[69] = 0;

	cube[70] = position.x - ((float)1 / 2) * sizeX;
	cube[71] = position.y + ((float)1 / 2) * sizeY;
	cube[72] = position.z - ((float)1 / 2) * sizeZ;
	cube[73] = 1;
	cube[74] = 1;

	cube[75] = position.x - ((float)1 / 2) * sizeX;
	cube[76] = position.y + ((float)1 / 2) * sizeY;
	cube[77] = position.z + ((float)1 / 2) * sizeZ;
	cube[78] = 0;
	cube[79] = 1;

	cube[80] = position.x + ((float)1 / 2) * sizeX;
	cube[81] = position.y - ((float)1 / 2) * sizeY;
	cube[82] = position.z + ((float)1 / 2) * sizeZ;
	cube[83] = 0;
	cube[84] = 1;

	cube[85] = position.x - ((float)1 / 2) * sizeX;
	cube[86] = position.y - ((float)1 / 2) * sizeY;
	cube[87] = position.z + ((float)1 / 2) * sizeZ;
	cube[88] = 1;
	cube[89] = 1;

	cube[90] = position.x - ((float)1 / 2) * sizeX;
	cube[91] = position.y - ((float)1 / 2) * sizeY;
	cube[92] = position.z - ((float)1 / 2) * sizeZ;
	cube[93] = 1;
	cube[94] = 0;

	cube[95] = position.x + ((float)1 / 2) * sizeX;
	cube[96] = position.y - ((float)1 / 2) * sizeY;
	cube[97] = position.z - ((float)1 / 2) * sizeZ;
	cube[98] = 0;
	cube[99] = 0;


	cube[100] = position.x - ((float)1 / 2) * sizeX;
	cube[101] = position.y + ((float)1 / 2) * sizeY;
	cube[102] = position.z - ((float)1 / 2) * sizeZ;
	cube[103] = 0;
	cube[104] = 1;


	cube[105] = position.x + ((float)1 / 2) * sizeX;
	cube[106] = position.y + ((float)1 / 2) * sizeY;
	cube[107] = position.z - ((float)1 / 2) * sizeZ;
	cube[108] = 1;
	cube[109] = 1;

	cube[110] = position.x + ((float)1 / 2) * sizeX;
	cube[111] = position.y + ((float)1 / 2) * sizeY;
	cube[112] = position.z + ((float)1 / 2) * sizeZ;
	cube[113] = 1;
	cube[114] = 0;

	cube[115] = position.x - ((float)1 / 2) * sizeX;
	cube[116] = position.y + ((float)1 / 2) * sizeY;
	cube[117] = position.z + ((float)1 / 2) * sizeZ;
	cube[118] = 0;
	cube[119] = 0;

	indices = new unsigned int[36];

	indices[0] = 2;
	indices[1] = 1;
	indices[2] = 0;
	indices[3] = 3;
	indices[4] = 2;
	indices[5] = 0;
	indices[6] = 4;
	indices[7] = 5;
	indices[8] = 6;
	indices[9] = 4;
	indices[10] = 6;
	indices[11] = 7;
	indices[12] = 8;
	indices[13] = 9;
	indices[14] = 10;
	indices[15] = 8;
	indices[16] = 10;
	indices[17] = 11;
	indices[18] = 14;
	indices[19] = 13;
	indices[20] = 12;
	indices[21] = 15;
	indices[22] = 14;
	indices[23] = 12;
	indices[24] = 16;
	indices[25] = 17;
	indices[26] = 18;
	indices[27] = 16;
	indices[28] = 18;
	indices[29] = 19;
	indices[30] = 22;
	indices[31] = 21;
	indices[32] = 20;
	indices[33] = 23;
	indices[34] = 22;
	indices[35] = 20;

	// Stride is the number of bytes per array element.
	auto stride = sizeof(GLfloat) * 5;
	// Data offset for texture coordinate in bytes.
	auto textureCoordOffset = sizeof(GLfloat) * 3;
	// Amount of index elements in total.
	drawCount = (sizeof(unsigned int)*36) / sizeof(unsigned int);


	// Generate Vertex Array and Vertex Buffer and point the area of data to assign to each attribute.
	glGenVertexArrays(1, &vao);

	glBindVertexArray(vao);
	glGenBuffers(1, &vertexVBO);
	glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
	glBufferData(GL_ARRAY_BUFFER, drawCount* stride, cube, GL_STATIC_DRAW);
	glEnableVertexAttribArray(static_cast<GLuint>(positionV));
	glVertexAttribPointer(static_cast<GLuint>(positionV), 3, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(static_cast<GLuint>(texCoordV));
	glVertexAttribPointer(static_cast<GLuint>(texCoordV), 2, GL_FLOAT, GL_FALSE, stride, (void*)textureCoordOffset);

	// Generate Index Buffer and define the amount of indices to point to.
	glGenBuffers(1, &indexVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, drawCount * sizeof(indices[0]), indices, GL_STATIC_DRAW);

	//Make sure to bind the vertex array to null if you wish to define more objects.
	glBindVertexArray(0);


	

}

void Cube::setTexture(sf::Texture& t)
{
	
	texture = &t;
	texture->generateMipmap();
}

void Cube::draw(sf::RenderWindow *window)
{
	
	if (texture == nullptr)
		return;
	if (visibility == false)
		return;

	window->setActive(true);
	sf::Texture::bind(texture);
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);

	

	window->setActive(false);
	
}

glm::vec3 Cube::getPosition()
{
	return position;
}

void Cube::move(uvec3 value)
{

	/*GLfloat tmpx = position.x - value.x;
	GLfloat tmpy = position.y - value.y;
	GLfloat tmpz = position.z - value.z;


	for (int i = 0; i < 120; i++)
	{
		if (i % 5 == 0)
		{
			cube[i] += tmpx;
		}
		else if (i % 5 == 1)
		{
			cube[i] += tmpy;
		}
		else if (i % 5 == 2)
		{
			cube[i] += tmpz;
		}
	}
	delete[] cube;

	cube = new GLfloat[120];

	cube[0] = value.x - ((float)1 / 2) * sizeX;
	cube[1] = value.y - ((float)1 / 2) * sizeY;
	cube[2] = value.z - ((float)1 / 2) * sizeZ;
	cube[3] = 1;
	cube[4] = 0;

	cube[5] = value.x + ((float)1 / 2) * sizeX;
	cube[6] = value.y - ((float)1 / 2) * sizeY;
	cube[7] = value.z - ((float)1 / 2) * sizeZ;
	cube[8] = 1;
	cube[9] = 0;

	cube[10] = value.x + ((float)1 / 2) * sizeX;
	cube[11] = value.y + ((float)1 / 2) * sizeY;
	cube[12] = value.z - ((float)1 / 2) * sizeZ;
	cube[13] = 1;
	cube[14] = 1;

	cube[15] = value.x - ((float)1 / 2) * sizeX;
	cube[16] = value.y + ((float)1 / 2) * sizeY;
	cube[17] = value.z - ((float)1 / 2) * sizeZ;
	cube[18] = 0;
	cube[19] = 1;

	cube[20] = value.x + ((float)1 / 2) * sizeX;
	cube[21] = value.y + ((float)1 / 2) * sizeY;
	cube[22] = value.z - ((float)1 / 2) * sizeZ;
	cube[23] = 1;
	cube[24] = 1;

	cube[25] = value.x + ((float)1 / 2) * sizeX;
	cube[26] = value.y + ((float)1 / 2) * sizeY;
	cube[27] = value.z + ((float)1 / 2) * sizeZ;
	cube[28] = 0;
	cube[29] = 1;

	cube[30] = value.x + ((float)1 / 2) * sizeX;
	cube[31] = value.y - ((float)1 / 2) * sizeY;
	cube[32] = value.z + ((float)1 / 2) * sizeZ;
	cube[33] = 0;
	cube[34] = 0;

	cube[35] = value.x + ((float)1 / 2) * sizeX;
	cube[36] = value.y - ((float)1 / 2) * sizeY;
	cube[37] = value.z - ((float)1 / 2) * sizeZ;
	cube[38] = 1;
	cube[39] = 0;

	cube[40] = value.x - ((float)1 / 2) * sizeX;
	cube[41] = value.y - ((float)1 / 2) * sizeY;
	cube[42] = value.z + ((float)1 / 2) * sizeZ;
	cube[43] = 0;
	cube[44] = 0;

	cube[45] = value.x + ((float)1 / 2) * sizeX;
	cube[46] = value.y - ((float)1 / 2) * sizeY;
	cube[47] = value.z + ((float)1 / 2) * sizeZ;
	cube[48] = 1;
	cube[49] = 0;

	cube[50] = value.x + ((float)1 / 2) * sizeX;
	cube[51] = value.y + ((float)1 / 2) * sizeY;
	cube[52] = value.z + ((float)1 / 2) * sizeZ;
	cube[53] = 1;
	cube[54] = 1;

	cube[55] = value.x - ((float)1 / 2) * sizeX;
	cube[56] = value.y + ((float)1 / 2) * sizeY;
	cube[57] = value.z + ((float)1 / 2) * sizeZ;
	cube[58] = 0;
	cube[59] = 1;

	cube[60] = value.x - ((float)1 / 2) * sizeX;
	cube[61] = value.y - ((float)1 / 2) * sizeY;
	cube[62] = value.z + ((float)1 / 2) * sizeZ;
	cube[63] = 0;
	cube[64] = 0;

	cube[65] = value.x - ((float)1 / 2) * sizeX;
	cube[66] = value.y - ((float)1 / 2) * sizeY;
	cube[67] = value.z - ((float)1 / 2) * sizeZ;
	cube[68] = 1;
	cube[69] = 0;

	cube[70] = value.x - ((float)1 / 2) * sizeX;
	cube[71] = value.y + ((float)1 / 2) * sizeY;
	cube[72] = value.z - ((float)1 / 2) * sizeZ;
	cube[73] = 1;
	cube[74] = 1;

	cube[75] = value.x - ((float)1 / 2) * sizeX;
	cube[76] = value.y + ((float)1 / 2) * sizeY;
	cube[77] = value.z + ((float)1 / 2) * sizeZ;
	cube[78] = 0;
	cube[79] = 1;

	cube[80] = value.x + ((float)1 / 2) * sizeX;
	cube[81] = value.y - ((float)1 / 2) * sizeY;
	cube[82] = value.z + ((float)1 / 2) * sizeZ;
	cube[83] = 0;
	cube[84] = 1;

	cube[85] = value.x - ((float)1 / 2) * sizeX;
	cube[86] = value.y - ((float)1 / 2) * sizeY;
	cube[87] = value.z + ((float)1 / 2) * sizeZ;
	cube[88] = 1;
	cube[89] = 1;

	cube[90] = value.x - ((float)1 / 2) * sizeX;
	cube[91] = value.y - ((float)1 / 2) * sizeY;
	cube[92] = value.z - ((float)1 / 2) * sizeZ;
	cube[93] = 1;
	cube[94] = 0;

	cube[95] = value.x + ((float)1 / 2) * sizeX;
	cube[96] = value.y - ((float)1 / 2) * sizeY;
	cube[97] = value.z - ((float)1 / 2) * sizeZ;
	cube[98] = 0;
	cube[99] = 0;


	cube[100] = value.x - ((float)1 / 2) * sizeX;
	cube[101] = value.y + ((float)1 / 2) * sizeY;
	cube[102] = value.z - ((float)1 / 2) * sizeZ;
	cube[103] = 0;
	cube[104] = 1;


	cube[105] = value.x + ((float)1 / 2) * sizeX;
	cube[106] = value.y + ((float)1 / 2) * sizeY;
	cube[107] = value.z - ((float)1 / 2) * sizeZ;
	cube[108] = 1;
	cube[109] = 1;

	cube[110] = value.x + ((float)1 / 2) * sizeX;
	cube[111] = value.y + ((float)1 / 2) * sizeY;
	cube[112] = value.z + ((float)1 / 2) * sizeZ;
	cube[113] = 1;
	cube[114] = 0;

	cube[115] = value.x - ((float)1 / 2) * sizeX;
	cube[116] = value.y + ((float)1 / 2) * sizeY;
	cube[117] = value.z + ((float)1 / 2) * sizeZ;
	cube[118] = 0;
	cube[119] = 0;

	auto stride = sizeof(GLfloat) * 5;
	// Data offset for texture coordinate in bytes.
	auto textureCoordOffset = sizeof(GLfloat) * 3;
	// Amount of index elements in total.
	drawCount = (sizeof(unsigned int) * 36) / sizeof(unsigned int);


	// Generate Vertex Array and Vertex Buffer and point the area of data to assign to each attribute.
	glGenVertexArrays(1, &vao);

	glBindVertexArray(vao);
	glGenBuffers(1, &vertexVBO);
	glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
	glBufferData(GL_ARRAY_BUFFER, drawCount * stride, cube, GL_STATIC_DRAW);
	glEnableVertexAttribArray(static_cast<GLuint>(positionV));
	glVertexAttribPointer(static_cast<GLuint>(positionV), 3, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(static_cast<GLuint>(texCoordV));
	glVertexAttribPointer(static_cast<GLuint>(texCoordV), 2, GL_FLOAT, GL_FALSE, stride, (void*)textureCoordOffset);

	// Generate Index Buffer and define the amount of indices to point to.
	glGenBuffers(1, &indexVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, drawCount * sizeof(indices[0]), indices, GL_STATIC_DRAW);

	//Make sure to bind the vertex array to null if you wish to define more objects.
	glBindVertexArray(0);
}
*/

#include "Cube.h"

Cube::Cube(vec3 position, sf::RenderWindow* window, float sizeX, float sizeY, float sizeZ, int positionV, int texCoordV)
{
	
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->sizeZ = sizeZ;
	this->position = position;
	this->positionV = positionV;
	this->texCoordV = texCoordV;
	window->setActive(true);
	initCube(position, sizeX, sizeY, sizeZ, positionV, texCoordV);
	window->setActive(false);
	
}

void Cube::setTexture(sf::Texture& t)
{

	texture = &t;
	texture->generateMipmap();
}

void Cube::draw(sf::RenderWindow* window, GLuint program, glm::mat4& viewProj)
{
	if (visibility == false)
	{
		return;
	}
	glUseProgram(program);

	//Set the uniforms for the shader to use.
	if (uniform[(int)UniformType::TransformPVM] >= 0)
		glUniformMatrix4fv((unsigned int)uniform[(int)UniformType::TransformPVM], 1, GL_FALSE, &viewProj[0][0]);
	sf::Texture::bind(texture);
	glBindVertexArray(vao);
	// Draw the cube
	glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);
	// Reset the vertex array bound, shader and texture for other assets to draw.
	glBindVertexArray(0);
	glUseProgram(0);

}

glm::vec3 Cube::getPosition()
{
	return position;
}

void Cube::move(vec3 value, sf::RenderWindow* window)
{
	position = value;

	std::cout << "dostaje:" << this->position.x << " " << this->position.y << " " << this->position.z << std::endl;

	window->setActive(true);
	//std::cout << position.x<<" " << position.y << " " << position.z<<std::endl;
	//std::cout << sizeX<<" " << sizeY << " " << sizeZ<<std::endl;
	initCube(position, sizeX, sizeY, sizeZ, positionV, texCoordV);
	window->setActive(false);
}

void Cube::initCube(vec3 position, float sizeX, float sizeY, float sizeZ, int positionV, int texCoordV)
{
	//Destroy all buffers, shaders and programs.
	glDeleteBuffers(1, &vertexVBO);
	glDeleteBuffers(1, &indexVBO);
	glDeleteVertexArrays(1, &vao);

	//Setting these values to zero will allow them to be initialised with new data on reset.
	vertexVBO = 0;
	indexVBO = 0;
	vao = 0;



	cube = new GLfloat[120];

	cube[0] = position.x - ((float)1 / 2) * sizeX;
	cube[1] = position.y - ((float)1 / 2) * sizeY;
	cube[2] = position.z - ((float)1 / 2) * sizeZ;
	cube[3] = 1;
	cube[4] = 0;

	cube[5] = position.x + ((float)1 / 2) * sizeX;
	cube[6] = position.y - ((float)1 / 2) * sizeY;
	cube[7] = position.z - ((float)1 / 2) * sizeZ;
	cube[8] = 1;
	cube[9] = 0;

	cube[10] = position.x + ((float)1 / 2) * sizeX;
	cube[11] = position.y + ((float)1 / 2) * sizeY;
	cube[12] = position.z - ((float)1 / 2) * sizeZ;
	cube[13] = 1;
	cube[14] = 1;

	cube[15] = position.x - ((float)1 / 2) * sizeX;
	cube[16] = position.y + ((float)1 / 2) * sizeY;
	cube[17] = position.z - ((float)1 / 2) * sizeZ;
	cube[18] = 0;
	cube[19] = 1;

	cube[20] = position.x + ((float)1 / 2) * sizeX;
	cube[21] = position.y + ((float)1 / 2) * sizeY;
	cube[22] = position.z - ((float)1 / 2) * sizeZ;
	cube[23] = 1;
	cube[24] = 1;

	cube[25] = position.x + ((float)1 / 2) * sizeX;
	cube[26] = position.y + ((float)1 / 2) * sizeY;
	cube[27] = position.z + ((float)1 / 2) * sizeZ;
	cube[28] = 0;
	cube[29] = 1;

	cube[30] = position.x + ((float)1 / 2) * sizeX;
	cube[31] = position.y - ((float)1 / 2) * sizeY;
	cube[32] = position.z + ((float)1 / 2) * sizeZ;
	cube[33] = 0;
	cube[34] = 0;

	cube[35] = position.x + ((float)1 / 2) * sizeX;
	cube[36] = position.y - ((float)1 / 2) * sizeY;
	cube[37] = position.z - ((float)1 / 2) * sizeZ;
	cube[38] = 1;
	cube[39] = 0;

	cube[40] = position.x - ((float)1 / 2) * sizeX;
	cube[41] = position.y - ((float)1 / 2) * sizeY;
	cube[42] = position.z + ((float)1 / 2) * sizeZ;
	cube[43] = 0;
	cube[44] = 0;

	cube[45] = position.x + ((float)1 / 2) * sizeX;
	cube[46] = position.y - ((float)1 / 2) * sizeY;
	cube[47] = position.z + ((float)1 / 2) * sizeZ;
	cube[48] = 1;
	cube[49] = 0;

	cube[50] = position.x + ((float)1 / 2) * sizeX;
	cube[51] = position.y + ((float)1 / 2) * sizeY;
	cube[52] = position.z + ((float)1 / 2) * sizeZ;
	cube[53] = 1;
	cube[54] = 1;

	cube[55] = position.x - ((float)1 / 2) * sizeX;
	cube[56] = position.y + ((float)1 / 2) * sizeY;
	cube[57] = position.z + ((float)1 / 2) * sizeZ;
	cube[58] = 0;
	cube[59] = 1;

	cube[60] = position.x - ((float)1 / 2) * sizeX;
	cube[61] = position.y - ((float)1 / 2) * sizeY;
	cube[62] = position.z + ((float)1 / 2) * sizeZ;
	cube[63] = 0;
	cube[64] = 0;

	cube[65] = position.x - ((float)1 / 2) * sizeX;
	cube[66] = position.y - ((float)1 / 2) * sizeY;
	cube[67] = position.z - ((float)1 / 2) * sizeZ;
	cube[68] = 1;
	cube[69] = 0;

	cube[70] = position.x - ((float)1 / 2) * sizeX;
	cube[71] = position.y + ((float)1 / 2) * sizeY;
	cube[72] = position.z - ((float)1 / 2) * sizeZ;
	cube[73] = 1;
	cube[74] = 1;

	cube[75] = position.x - ((float)1 / 2) * sizeX;
	cube[76] = position.y + ((float)1 / 2) * sizeY;
	cube[77] = position.z + ((float)1 / 2) * sizeZ;
	cube[78] = 0;
	cube[79] = 1;

	cube[80] = position.x + ((float)1 / 2) * sizeX;
	cube[81] = position.y - ((float)1 / 2) * sizeY;
	cube[82] = position.z + ((float)1 / 2) * sizeZ;
	cube[83] = 0;
	cube[84] = 1;

	cube[85] = position.x - ((float)1 / 2) * sizeX;
	cube[86] = position.y - ((float)1 / 2) * sizeY;
	cube[87] = position.z + ((float)1 / 2) * sizeZ;
	cube[88] = 1;
	cube[89] = 1;

	cube[90] = position.x - ((float)1 / 2) * sizeX;
	cube[91] = position.y - ((float)1 / 2) * sizeY;
	cube[92] = position.z - ((float)1 / 2) * sizeZ;
	cube[93] = 1;
	cube[94] = 0;

	cube[95] = position.x + ((float)1 / 2) * sizeX;
	cube[96] = position.y - ((float)1 / 2) * sizeY;
	cube[97] = position.z - ((float)1 / 2) * sizeZ;
	cube[98] = 0;
	cube[99] = 0;


	cube[100] = position.x - ((float)1 / 2) * sizeX;
	cube[101] = position.y + ((float)1 / 2) * sizeY;
	cube[102] = position.z - ((float)1 / 2) * sizeZ;
	cube[103] = 0;
	cube[104] = 1;


	cube[105] = position.x + ((float)1 / 2) * sizeX;
	cube[106] = position.y + ((float)1 / 2) * sizeY;
	cube[107] = position.z - ((float)1 / 2) * sizeZ;
	cube[108] = 1;
	cube[109] = 1;

	cube[110] = position.x + ((float)1 / 2) * sizeX;
	cube[111] = position.y + ((float)1 / 2) * sizeY;
	cube[112] = position.z + ((float)1 / 2) * sizeZ;
	cube[113] = 1;
	cube[114] = 0;

	cube[115] = position.x - ((float)1 / 2) * sizeX;
	cube[116] = position.y + ((float)1 / 2) * sizeY;
	cube[117] = position.z + ((float)1 / 2) * sizeZ;
	cube[118] = 0;
	cube[119] = 0;

	// Define indices for 3D cube.
	static const unsigned int indices[] =
	{
		2, 1, 0, 3, 2, 0, //front
		4, 5, 6, 4, 6, 7, //right
		8, 9, 10, 8, 10, 11, //back
		14, 13, 12, 15, 14, 12, //left
		16, 17, 18, 16, 18, 19, //upper
		22, 21, 20, 23, 22, 20  //bottom
	};

	// Stride is the number of bytes per array element.
	auto stride = sizeof(GLfloat) * 5;
	// Data offset for texture coordinate in bytes.
	auto textureCoordOffset = sizeof(GLfloat) * 3;
	// Amount of index elements in total.
	drawCount = sizeof(indices) / sizeof(unsigned int);


	// Generate Vertex Array and Vertex Buffer and point the area of data to assign to each attribute.
	glGenVertexArrays(1, &vao);

	glBindVertexArray(vao);
	glGenBuffers(1, &vertexVBO);
	glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
	glBufferData(GL_ARRAY_BUFFER, drawCount * stride, cube, GL_STATIC_DRAW);
	glEnableVertexAttribArray(static_cast<GLint>(positionV));
	glVertexAttribPointer(static_cast<GLint>(positionV), 3, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(static_cast<GLint>(texCoordV));
	glVertexAttribPointer(static_cast<GLint>(texCoordV), 2, GL_FLOAT, GL_FALSE, stride, (void*)textureCoordOffset);

	// Generate Index Buffer and define the amount of indices to point to.
	glGenBuffers(1, &indexVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, drawCount * sizeof(indices[0]), indices, GL_STATIC_DRAW);

	//Make sure to bind the vertex array to null if you wish to define more objects.
	glBindVertexArray(0);

	// Make the window no longer the active window for OpenGL calls

}


