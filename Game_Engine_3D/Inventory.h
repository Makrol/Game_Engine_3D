#pragma once

#include "Slot.h"
/**
 * @brief Obiekt z przedmiotami posiadanymi przez gracza
 *
 */
class Inventory
{
private:
	bool navigationKeyPressed;/*!<Informacja o satnie wci�ni�cia przycisk�w do nawigowania po inventory>*/
	std::vector<ItemSlot> slots;/*!<Kontener z slotami nale��cyni do inventory>*/
	float sizeX;/*!<Rozmiar na osi X>*/
	float sizeY;/*!<Rozmiar na osi y>*/
	int selectedItem;/*!<Id obecnie wybranego slotu w inventory>*/
	int numberOfColumns;/*!<Ilo�� kolumn w inventory>*/
	int numberOfRows;/*!<Ilo�� wierszy w inventory>*/
	RectangleShape background;/*!<T�o inventory>*/
	/**
	 * @brief Stworzenie odpowiedniej ilo�ci slot�w
	 *
	 */
	void createSlots();
public:
	bool visable;
	/**
	 * @brief Kasowanie wszystkich przedmiot�w z gracza
	 *
	 */
	void clear();
	/**
	 * @brief Konstruktor inicjuj�cy obiekt
	 *
	 */
	Inventory();
	/**
	 * @brief Aktualizacja stanu obiektu
	 *
	 * @param itemToEquip informacja zwrotna o tym czy przedmiot zosta� zlecony do zao�enia
	 * @param item przedmiot zwrotny zlecony do za�o�enia
	 */
	void update(bool& itemToEquip, Item& item);
	/**
	 * @brief dodanie przedmiotu do inventory
	 *
	 * @param tmp dodawany przedmiot
	 */
	void addItem(Item tmp);
	/**
	 * @brief wy�wietlanie inventory gracza
	 *
	 * @param target wska�nik do okna gry
	 * @param pos pozyja kamery na mapie
	 */
	void show(RenderTarget* target, Vector2f pos);

};

