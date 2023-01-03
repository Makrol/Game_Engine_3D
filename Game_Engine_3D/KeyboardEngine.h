#pragma once
#include "InputEngine.h"

using namespace sf;
/**
 * @brief Klasa klawiatury
 */
class KeyboardEngine : public InputEngine
{
public:
	/**
	 * @brief Wykonuje akcje dla odczytanych zdarzeñ
	 *
	 * \param eventHendler WskaŸnik na obiekt z informacjami o odczytanych zdarzeniach
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 */
	void pollEvent(Event* eventHendler, RenderWindow* window);
};
