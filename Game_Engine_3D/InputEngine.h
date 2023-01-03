#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <set>
#include "Vector4d.h"
using namespace sf;
/**
 * @brief Obs³uga wejœcia
 */
class InputEngine
{
protected:
	std::map<int, Vector4d> keyClickArea; /*!<Mapa z przyciskami przypisanymi do obszaru w jakim mog¹ dzia³aæ>*/
	std::map<int, void(*)()> keyActionContener;/*!<Mapa z przyciskami przypisanymi do odpowiednich funkcji>*/
	std::set<int> spamAbleKeys;/*!<Zbiór przycisków spamuj¹cych>*/
	bool spamButton;/*!<Zmienna czy jest przyciskiem spamuj¹cym>*/
	int lastButton;/*!<Ostatni przycisk wciœniêty>*/
	/**
	 * @brief Wykonaj akcje
	 *
	 * \param eventHendler WskaŸnik na obiekt z informacjami o odczytanych zdarzeniach
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 */
	void doAction(Event* eventHendler, RenderWindow* window);

public:
	/**
	 * @brief Wykonuje akcje dla odczytanych zdarzeñ
	 *
	 * \param eventHendler WskaŸnik na obiekt z informacjami o odczytanych zdarzeniach
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 */
	virtual void pollEvent(Event* eventHendler, RenderWindow* window) = 0;
	/**
	 * @brief Rejestruje akcje
	 *
	 * \param key Przycisk
	 * \param func WskaŸnik do funkcji po wciœniêciu przycisku
	 * \param spamAble Parametr czy mo¿na spamowaæ
	 */
	void registerNewAction(int key, void(*func)(), bool spamAble);
	/**
	 * @brief Rejestruje akcje
	 *
	 * \param key Przycisk
	 * \param func WskaŸnik do funkcji po wciœniêciu przycisku
	 * \param px1 Punkt 1 na osi X
	 * \param py1 Punkt 1 na osi Y
	 * \param px2 Punkt 2 na osi X
	 * \param py2 Punkt 2 na osi Y
	 * \param spamAble Parametr czy mo¿na spamowaæ
	 */
	void registerNewActionInArea(int key, void(*func)(), int px1, int py1, int px2, int py2, bool spamAble);

	void reset();
};