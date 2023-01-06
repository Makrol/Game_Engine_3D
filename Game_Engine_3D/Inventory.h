#pragma once

#include "Slot.h"
/**
 * @brief Obiekt z przedmiotami posiadanymi przez gracza
 *
 */
class Inventory
{
private:
	bool navigationKeyPressed;/*!<Informacja o satnie wciœniêcia przycisków do nawigowania po inventory>*/
	std::vector<ItemSlot> slots;/*!<Kontener z slotami nale¿¹cyni do inventory>*/
	float sizeX;/*!<Rozmiar na osi X>*/
	float sizeY;/*!<Rozmiar na osi y>*/
	int selectedItem;/*!<Id obecnie wybranego slotu w inventory>*/
	int numberOfColumns;/*!<Iloœæ kolumn w inventory>*/
	int numberOfRows;/*!<Iloœæ wierszy w inventory>*/
	RectangleShape background;/*!<T³o inventory>*/
	/**
	 * @brief Stworzenie odpowiedniej iloœci slotów
	 *
	 */
	void createSlots();
public:
	bool visable;
	/**
	 * @brief Kasowanie wszystkich przedmiotów z gracza
	 *
	 */
	void clear();
	/**
	 * @brief Konstruktor inicjuj¹cy obiekt
	 *
	 */
	Inventory();
	/**
	 * @brief Aktualizacja stanu obiektu
	 *
	 * @param itemToEquip informacja zwrotna o tym czy przedmiot zosta³ zlecony do zao¿enia
	 * @param item przedmiot zwrotny zlecony do za³o¿enia
	 */
	void update(bool& itemToEquip, Item& item);
	/**
	 * @brief dodanie przedmiotu do inventory
	 *
	 * @param tmp dodawany przedmiot
	 */
	void addItem(Item tmp);
	/**
	 * @brief wyœwietlanie inventory gracza
	 *
	 * @param target wskaŸnik do okna gry
	 * @param pos pozyja kamery na mapie
	 */
	void show(RenderTarget* target, Vector2f pos);

};

