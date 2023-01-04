#pragma once
#include "Slot.h"
/**
 * @brief Klasa z wyposarzeniem gracza w postaci za�o�onych przedmiot�w oraz statystyk
 *
 */
class Equipment
{
private:
	std::vector<ItemSlot> slots;/*!<Kontener z slotami znajduj�cymi si� w equipment gracza>*/
	Sprite playerIcon;/*!<Ikona gracza wy�wietlana w equipment>*/
	float sizeX;/*!<Pozycja okna na osi x>*/
	float sizeY;/*!<Pozycja okna na osi y>*/

	Text armor;/*!<Tekst do statystyki obrony>*/
	Text damage;/*!<Tekst do statystyki obra�e�>*/
	Text health;/*!<Tekst do statystyki zdrowia>*/
	Text agility;/*!<Tekst do statystyki zwinno�ci>*/

	double* armorValues;/*!<>*/
	double* damageValues;/*!<>*/
	double* agilityValues;/*!<>*/
	double* healthValues;/*!<>*/

	Font gameFont;/*!<Trzcionka>*/

	RectangleShape background;/*!<T�o okna equipment>*/
	/**
	 * @brief Ustawienie pozycjislot�w w wyposarzeniu
	 *
	 * @param bcgPos pozycja t�a wypozarzenia na ekranie
	 */
	void positioningSlots(Vector2f bcgPos);
	/**
	 * @brief Aktulizacja stanu statystyk wyswietlanych w wyposarzeniu
	 *
	 * @param pos pozycja t�a wypozarzenia na ekranie
	 */
	void updateStatistics(Vector2f pos);
	/**
	 * @brief Tworzenie wyaganej ilo�ci slot�w
	 *
	 */
	void createSlots();

	struct statistics bonusStat;


public:
	/**
	 * @brief Przekopiowanie wska�nik�w statystyk gracza
	 *
	 * @param health wska�nik na warto�� zdrowia
	 * @param damage wska�nik na warto�� obra�e�
	 * @param armor wska�nik na warto�� obrony
	 * @param agility wska�nik na warto�� zwinno�ci
	 */
	void setDefaultParameters(double* health, double* damage, double* armor, double* agility);
	/**
	 * @brief ustawienie trzcionka
	 *
	 * @param font referencja do obiektu Font
	 */
	void setFonts(const Font& font);
	bool visable;
	/**
	 * @brief Konstruktor inicjuj�cy obiekt
	 *
	 */
	Equipment();
	/**
	 * @brief Aktualizacja wszystkich element�w obiektu
	 *
	 */
	void update();
	/**
	 * @brief usuwanie przedmiot�w i zerowanie statystyk
	 *
	 */
	void clear();
	/**
	 * @brief Get the Stat object
	 *
	 * @return struct statistics - struktura zawieraj�ca informacje o statystykach gracza
	 */
	struct statistics getStat();
	/**
	 * @brief Dodawanie przedmiotu do ekwipunku
	 *
	 * @param item przedmiot kt�ry ma zosta� dodany
	 * @param tmpbool infromacja zwrotna o tym czy dosz�o do podmiany przedmiot�w
	 */
	void addItem(Item& item, bool& tmpbool);
	/**
	 * @brief Ustawienie ikony dla tekstury gracza wy�wietlaniej w wyposa�eniu
	 *
	 * @param player wska�nik do tekstury gracza
	 */
	void setIconSprite(Texture* player);
	/**
	 * @brief Wy�wietlenie wyposarzenia gracza
	 *
	 * @param target wska�nik do okna gry
	 * @param pos pozycja kamery gry
	 */
	void show(RenderTarget* target, Vector2f pos);

};

