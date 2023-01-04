#pragma once
//#include "Animation.h"
#include <map>

#include <iostream>
#include <ctime>
//#include "HealthBar.h"
//#include "MapObjects.h"
#include "Item.h"
/**
 * @brief Klasa slotu w którym znajduj¹ siê przedmioty
 *
 */
class ItemSlot
{
private:
	friend class Inventory;
	friend class Equipment;
	Item item;/*!<Przedmiot znajduj¹cy siê w slocie>*/
	RectangleShape slot;/*!<Cia³o slota>*/
public:
	bool empty;
	/**
	 * @brief metoda s³u¿¹ca do ustawienia przedmiot w slocie
	 *
	 * @param tmp przedmiot który wk³adamy do slota
	 */
	void setItem(Item tmp);
	/**
	 * @brief konstruktor zawieraj¹cy podstawowe parametry do stworzenia slota
	 *
	 * @param pos pozycja slotu
	 * @param size rozmiar slotu
	 * @param color kolor slotu
	 */
	ItemSlot(Vector2f pos, Vector2f size, Color color);
	/**
	 * @brief metoda zawieraj¹ca pozycje obiektu
	 *
	 * @return wektor z pozycj¹ obiektu
	 */
	Vector2f getPosition();
	/**
	 * @brief metoda ustawiaj¹ca pozycje slota
	 *
	 * @param pos pozycje slota
	 */
	void setPosition(Vector2f pos);
	/**
	 * @brief metoda zawieraj¹ca wielkoœæ slota
	 *
	 * @return wektor zawieraj¹cy wielkoœæ slota
	 */
	Vector2f getSize();
	/**
	 * @brief metoda odpowiedzialna za renderowanie slotów
	 *
	 * @param target wskaŸnik na okno gry
	 */
	void render(RenderTarget* target);
};

