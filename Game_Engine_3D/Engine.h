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
#include "GameMap.h"
#include "Player.h"
#include "Equipment.h"
#include "Inventory.h"
#include "Enemy.h"

class Engine
{
public:
	///Basic vertex shader that transforms the vertex position based on a projection view matrix and passes the texture coordinate to the fragment shader.
	const std::string defaultVertexShader =
		"#version 330\n"\
		"attribute vec3 position;"\
		"attribute vec2 texCoord;" \
		"uniform mat4 pvm;" \

		"varying vec2 uv;" \

		"void main() {"\
		"	gl_Position = pvm * vec4(position, 1.0);"\
		"	uv = texCoord;"\
		"}";

	///Basic fragment shader that returns the colour of a pixel based on the input texture and its coordinate.
	const std::string defaultFragShader =
		"#version 330\n" \
		"uniform sampler2D texture;" \
		"varying vec2 uv;" \

		"void main() {" \
		"	gl_FragColor = texture2D(texture, uv);" \
		"}";



	///Shader Types
	enum class ShaderType { Vertex, Fragment, Geometry, Count };
	///Standard Uniforms in the shader.
	enum class UniformType { TransformPVM, Count };
	///Vertex attributes for shaders and the input vertex array.
	enum class VertexAttribute { Position, TexCoord, COUNT };

	///Shader Program
	GLuint program = 0;

	///List of shaders set up for a 3D scene.
	GLuint shader[static_cast<unsigned int>(ShaderType::Count)];
	///List of uniforms that can be defined values for the shader.
	GLint uniform[static_cast<unsigned int>(UniformType::Count)];

	

	///Checks for any errors specific to the shaders. It will output any errors within the shader if it's not valid.
	void checkError(GLuint l_shader, GLuint l_flag, bool l_program, const std::string& l_errorMsg)
	{
		GLint success = 0;
		GLchar error[1024] = { 0 };
		if (l_program) { glGetProgramiv(l_shader, l_flag, &success); }
		else { glGetShaderiv(l_shader, l_flag, &success); }

		if (success) { return; }
		if (l_program) {
			glGetProgramInfoLog(l_shader, sizeof(error), nullptr, error);
		}
		else {
			glGetShaderInfoLog(l_shader, sizeof(error), nullptr, error);
		}

		std::cout << l_errorMsg << "\n";
	}
	///Creates and compiles a shader.
	GLuint buildShader(const std::string& l_src, unsigned int l_type)
	{
		GLuint shaderID = glCreateShader(l_type);
		if (!shaderID) {
			std::cout << "Bad shader type!";
			return 0;
		}
		const GLchar* sources[1];
		GLint lengths[1];
		sources[0] = l_src.c_str();
		lengths[0] = l_src.length();
		glShaderSource(shaderID, 1, sources, lengths);
		glCompileShader(shaderID);
		checkError(shaderID, GL_COMPILE_STATUS, false, "Shader compile error: ");
		return shaderID;
	}
	///Function to load the shaders from string data.
	void LoadFromMemory(const std::string& shaderData, ShaderType type)
	{
		if (shaderData.empty())
			return;

		if (shader[static_cast<unsigned int>(type)])
		{
			glDetachShader(program, shader[static_cast<unsigned int>(type)]);
			glDeleteShader(shader[static_cast<unsigned int>(type)]);
		}

		switch (type)
		{
		case ShaderType::Vertex:
			shader[static_cast<unsigned int>(type)] = buildShader(shaderData, GL_VERTEX_SHADER);
			break;
		case ShaderType::Geometry:
			shader[static_cast<unsigned int>(type)] = buildShader(shaderData, GL_GEOMETRY_SHADER);
			break;
		case ShaderType::Fragment:
			shader[static_cast<unsigned int>(type)] = buildShader(shaderData, GL_FRAGMENT_SHADER);
			break;
		default:
			break;
		}

		if (program == 0)
		{
			program = glCreateProgram();
		}

		glAttachShader(program, shader[static_cast<unsigned int>(type)]);
		glBindAttribLocation(program, static_cast<GLuint>(VertexAttribute::Position), "position");
		glBindAttribLocation(program, static_cast<GLuint>(VertexAttribute::TexCoord), "texCoord");

		glLinkProgram(program);
		checkError(program, GL_LINK_STATUS, true, "Shader link error:");
		glValidateProgram(program);
		checkError(program, GL_VALIDATE_STATUS, true, "Invalid shader:");

		uniform[static_cast<unsigned int>(UniformType::TransformPVM)] = glGetUniformLocation(program, "pvm");
	}

	bool exit = false;
	bool sRgb = false;
	bool mipmapEnabled;



	Engine();
	Camera engineCamera;
	void initEngine();
	void update();
	void render();
	void initWindow();
	void initGlew();
	void loadFiles();
	void create3DObjects();
	void create2DObjects();
	bool testB = false;
	int y=0;
	int z=-100;
	ContextSettings contextSettings;
	Texture cubeTexture;
	RenderWindow window;
	Clock mainClock;
	float frameTime;

	sf::Event event;
	sf::Texture texture;
	sf::Texture grasTex;
	sf::Texture squereTex;
	sf::Texture playerTex;
	sf::Texture enemyTex;
	sf::Texture movePointTex;
	glm::mat4 projection;
	glm::mat4 matrix_pos;
	GameMap *gamemap;
	Player *player;
	Equipment equ;
	Inventory inv;
	Texture equTex;
	Font font;
	Text text;
	bool IKeyReleased = true;
	bool EKeyReleased = true;
	std::list<Enemy*> enemyList;
	
	void mainLoop();

};