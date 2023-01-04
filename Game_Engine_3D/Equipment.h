#pragma once
#include "Slot.h"
/**
 * @brief Klasa z wyposarzeniem gracza w postaci za³o¿onych przedmiotów oraz statystyk
 *
 */
class Equipment
{
private:
	std::vector<ItemSlot> slots;/*!<Kontener z slotami znajduj¹cymi siê w equipment gracza>*/
	Sprite playerIcon;/*!<Ikona gracza wyœwietlana w equipment>*/
	float sizeX;/*!<Pozycja okna na osi x>*/
	float sizeY;/*!<Pozycja okna na osi y>*/

	Text armor;/*!<Tekst do statystyki obrony>*/
	Text damage;/*!<Tekst do statystyki obra¿eñ>*/
	Text health;/*!<Tekst do statystyki zdrowia>*/
	Text agility;/*!<Tekst do statystyki zwinnoœci>*/

	double* armorValues;/*!<>*/
	double* damageValues;/*!<>*/
	double* agilityValues;/*!<>*/
	double* healthValues;/*!<>*/

	Font gameFont;/*!<Trzcionka>*/

	RectangleShape background;/*!<T³o okna equipment>*/
	/**
	 * @brief Ustawienie pozycjislotów w wyposarzeniu
	 *
	 * @param bcgPos pozycja t³a wypozarzenia na ekranie
	 */
	void positioningSlots(Vector2f bcgPos);
	/**
	 * @brief Aktulizacja stanu statystyk wyswietlanych w wyposarzeniu
	 *
	 * @param pos pozycja t³a wypozarzenia na ekranie
	 */
	void updateStatistics(Vector2f pos);
	/**
	 * @brief Tworzenie wyaganej iloœci slotów
	 *
	 */
	void createSlots();

	struct statistics bonusStat;


public:
	/**
	 * @brief Przekopiowanie wska¿ników statystyk gracza
	 *
	 * @param health wska¿nik na wartoœæ zdrowia
	 * @param damage wska¿nik na wartoœæ obra¿eñ
	 * @param armor wska¿nik na wartoœæ obrony
	 * @param agility wska¿nik na wartoœæ zwinnoœci
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
	 * @brief Konstruktor inicjuj¹cy obiekt
	 *
	 */
	Equipment();
	/**
	 * @brief Aktualizacja wszystkich elementów obiektu
	 *
	 */
	void update();
	/**
	 * @brief usuwanie przedmiotów i zerowanie statystyk
	 *
	 */
	void clear();
	/**
	 * @brief Get the Stat object
	 *
	 * @return struct statistics - struktura zawieraj¹ca informacje o statystykach gracza
	 */
	struct statistics getStat();
	/**
	 * @brief Dodawanie przedmiotu do ekwipunku
	 *
	 * @param item przedmiot który ma zostaæ dodany
	 * @param tmpbool infromacja zwrotna o tym czy dosz³o do podmiany przedmiotów
	 */
	void addItem(Item& item, bool& tmpbool);
	/**
	 * @brief Ustawienie ikony dla tekstury gracza wyœwietlaniej w wyposa¿eniu
	 *
	 * @param player wskaŸnik do tekstury gracza
	 */
	void setIconSprite(Texture* player);
	/**
	 * @brief Wyœwietlenie wyposarzenia gracza
	 *
	 * @param target wskaŸnik do okna gry
	 * @param pos pozycja kamery gry
	 */
	void show(RenderTarget* target, Vector2f pos);

};

