#include "Engine.h"

Engine::Engine()
{	
	initEngine();
	mainLoop();
}

void Engine::initEngine()
{
	
	initWindow();
	initGlew();
	loadFiles();
	create3DObjects();
	create2DObjects();
	
}

void Engine::update()
{	
	//upadeCamera();

	bool tmpBool;
	Item tmpItem;
	inv.update(tmpBool, tmpItem);

	frameTime = mainClock.restart().asSeconds();

	while (window.pollEvent(event))
	{
		// Close window: exit
		if (event.type == sf::Event::Closed)
		{
			exit = true;
			window.close();
		}

		// Escape key: exit
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
		{
			exit = true;
			window.close();
		}

		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::A))
		{
			engineCamera.move(glm::vec3(-1000 * frameTime, 0, 0));
		}
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::D))
		{
			engineCamera.move(glm::vec3(1000 * frameTime, 0, 0));
		}
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::W))
		{
			engineCamera.rotate(1000, 0, 0, frameTime);
		}
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::S))
		{
			engineCamera.rotate(-1000, 0, 0, frameTime);
		}
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::R))
		{
			engineCamera.rotate(0,1000,0,frameTime);
		}
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::T))
		{
			engineCamera.rotate(0, -1000, 0, frameTime);
		}


		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
		{
			vec3 tmpPos = gamemap->getPos(player->posIndex - 1);
			tmpPos.y = 60;
			player->move(&window,tmpPos, player->posIndex - 1,gamemap->getSize());
		}
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
		{
			vec3 tmpPos = gamemap->getPos(player->posIndex + 1);
			tmpPos.y = 60;
			player->move(&window, tmpPos, player->posIndex + 1, gamemap->getSize());

		}
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up))
		{
			vec3 tmpPos = gamemap->getPos(player->posIndex - gamemap->getSize());
			tmpPos.y = 60;

			player->move(&window, tmpPos, player->posIndex - gamemap->getSize(), gamemap->getSize());
		}
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down))
		{
			vec3 tmpPos = gamemap->getPos(player->posIndex - gamemap->getSize());
			tmpPos.y = 60;
			player->move(&window, tmpPos, player->posIndex + gamemap->getSize(), gamemap->getSize());
		}
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Enter))
		{
			gamemap->showAllMoves(player->posIndex);
			player->lockIndex = player->posIndex;
		}



		// Adjust the viewport when the window is resized
		if (event.type == sf::Event::Resized)
		{
			// Make the window the active window for OpenGL calls
			window.setActive(true);

			glViewport(0, 0, event.size.width, event.size.height);
			//createProjection();
			engineCamera.resizeWindowProjection(window.getSize().x,window.getSize().y);

			// Make the window no longer the active window for OpenGL calls
			window.setActive(false);
		}
		if (Keyboard::isKeyPressed(Keyboard::I))
		{
			if (IKeyReleased)
			{
				if (inv.visable == true)
					inv.visable = false;
				else
					inv.visable = true;
			}

			IKeyReleased = false;
		}
		else if (!Keyboard::isKeyPressed(Keyboard::I))
		{
			IKeyReleased = true;
		}

		if (Keyboard::isKeyPressed(Keyboard::E))
		{
			if (EKeyReleased)
			{
				if (equ.visable == true)
					equ.visable = false;
				else
					equ.visable = true;
			}

			EKeyReleased = false;
		}
		else if (!Keyboard::isKeyPressed(Keyboard::E))
		{
			EKeyReleased = true;
		}
	}


}

void Engine::render()
{
	
	glClearColor(0.53f, 0.81f, 0.92f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	

	window.setActive(true);


	engineCamera.transformCamera(uniform, (int)UniformType::TransformPVM, program, frameTime);

	

	gamemap->showMap(window, program, *(engineCamera.getView()));
	player->render(&window, program, *(engineCamera.getView()));


	for (std::list<Enemy*>::iterator it = enemyList.begin(); it != enemyList.end(); ++it) {
		(*it)->render(&window, program, *(engineCamera.getView()));
	}

	window.setActive(false);

	
		window.pushGLStates();
		window.draw(text);
		equ.show(&window, sf::Vector2f(400, 400));
		inv.show(&window, sf::Vector2f(970, 0));
		window.popGLStates();
	
	
	window.display();
}

void Engine::initWindow()
{
	sf::ContextSettings contextSettings;
	contextSettings.depthBits = 24;
	contextSettings.sRgbCapable = sRgb;

	// Create the main window
	window.create(sf::VideoMode(1280, 720), "Medieval Story", sf::Style::Default, contextSettings);
	window.setVerticalSyncEnabled(true);
	engineCamera = Camera(1280, 720);
}

void Engine::initGlew()
{
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		//koniec programu error
		//return EXIT_FAILURE;
	}
}

void Engine::loadFiles()
{


	if (!texture.loadFromFile("resources/texture.jpg"))
	{
		std::cout << "texture";
	}
	texture.generateMipmap();
	
	if (!grasTex.loadFromFile("resources/grass.png"))
	{
		std::cout << "texture";
	}
	grasTex.generateMipmap();

	if (!squereTex.loadFromFile("resources/squere.png"))
	{
		std::cout << "texture";
	}
	squereTex.generateMipmap();

	if (!playerTex.loadFromFile("resources/player.png"))
	{
		std::cout << "texture";
	}
	playerTex.generateMipmap();
	if (!movePointTex.loadFromFile("resources/point.jpg"))
	{
		std::cout << "texture";
	}
	movePointTex.generateMipmap();

	if (!font.loadFromFile("resources/font.ttf"))
	{
		std::cout << "font";
	}
	if (!equTex.loadFromFile("resources/player.png"))
	{
		std::cout << "texture";
	}
	if (!enemyTex.loadFromFile("resources/skeleton.png"))
	{
		std::cout << "texture";
	}
	enemyTex.generateMipmap();

	text.setString("My po te pedrivy ");
	text.setFont(font);
	text.setFillColor(sf::Color(255, 0, 0, 170));
	text.setCharacterSize(50);
	text.setPosition(0, 0);
}

void Engine::create3DObjects()
{

	window.setActive(true);


	if (program == 0)
	{
		LoadFromMemory(defaultVertexShader, ShaderType::Vertex);
		LoadFromMemory(defaultFragShader, ShaderType::Fragment);
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	gamemap = new GameMap(&window,15, grasTex, squereTex,movePointTex, (int)VertexAttribute::Position, (int)VertexAttribute::TexCoord);
	player = new Player(playerTex,&window, vec3(gamemap->getPos(5).x, 60, gamemap->getPos(5).z), 40, 70, 40, (int)VertexAttribute::Position, (int)VertexAttribute::TexCoord);
	player->posIndex = 5;



	enemyList.push_back(new Enemy(enemyTex, &window, vec3(0, 60, 0), 40, 70, 40, (int)VertexAttribute::Position, (int)VertexAttribute::TexCoord));



	window.setActive(false);

	mipmapEnabled = true;


	


}

void Engine::create2DObjects()
{
	equ.setIconSprite(&playerTex);
	equ.setFonts(font);
	equ.setDefaultParameters(player->getHealthValues(), player->getDamageValues(), player->getArmorValues(), player->getAgilityValues());
}







void Engine::mainLoop()
{
	while (window.isOpen())
	{
		update();
		render();
	}
	
}
