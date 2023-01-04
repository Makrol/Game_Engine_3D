#pragma once
//#include "Animation.h"
#include <map>

#include <iostream>
#include <ctime>
//#include "HealthBar.h"
//#include "MapObjects.h"
#include "Item.h"
/**
 * @brief Klasa slotu w kt�rym znajduj� si� przedmioty
 *
 */
class ItemSlot
{
private:
	friend class Inventory;
	friend class Equipment;
	Item item;/*!<Przedmiot znajduj�cy si� w slocie>*/
	RectangleShape slot;/*!<Cia�o slota>*/
public:
	bool empty;
	/**
	 * @brief metoda s�u��ca do ustawienia przedmiot w slocie
	 *
	 * @param tmp przedmiot kt�ry wk�adamy do slota
	 */
	void setItem(Item tmp);
	/**
	 * @brief konstruktor zawieraj�cy podstawowe parametry do stworzenia slota
	 *
	 * @param pos pozycja slotu
	 * @param size rozmiar slotu
	 * @param color kolor slotu
	 */
	ItemSlot(Vector2f pos, Vector2f size, Color color);
	/**
	 * @brief metoda zawieraj�ca pozycje obiektu
	 *
	 * @return wektor z pozycj� obiektu
	 */
	Vector2f getPosition();
	/**
	 * @brief metoda ustawiaj�ca pozycje slota
	 *
	 * @param pos pozycje slota
	 */
	void setPosition(Vector2f pos);
	/**
	 * @brief metoda zawieraj�ca wielko�� slota
	 *
	 * @return wektor zawieraj�cy wielko�� slota
	 */
	Vector2f getSize();
	/**
	 * @brief metoda odpowiedzialna za renderowanie slot�w
	 *
	 * @param target wska�nik na okno gry
	 */
	void render(RenderTarget* target);
};

