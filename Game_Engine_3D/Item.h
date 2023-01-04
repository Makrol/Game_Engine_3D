#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
/**
 * @brief Struktura statystyk
 *
 */
struct statistics
{
	double armor;
	double agility;
	double damage;
};
/**
 * @brief Klasa przedmiotów dostêpnych w grze
 *
 */
class Item
{
private:
	Sprite body;/*!<Cia³o obiektu posiadaj¹ce tekture wyœwietlane na ekranie>*/
	std::string name;/*!<Nazwa przedmiotu>*/

	struct statistics stat;/*!<Struktura z statystykami przedmiotu>*/
public:
	int slotId;/*!<Typ przedmiotu>*/
	/**
	 * @brief Konstruktor domyœlny obiektu
	 *
	 */
	Item();
	/**
	 * @brief Konstruktor inicjuj¹cy wartoœciami obiekt
	 *
	 * @param tex wskaŸnik na teksture przedmiotu
	 * @param pos pozycja przedmiotu
	 * @param name nazwa przedmiotu
	 * @param armor parametr obronny
	 * @param agility parametr zwinnosci
	 * @param damage parametr ataku
	 * @param slotId typ przedmiotu
	 */
	Item(Texture* tex, Vector2f pos, std::string name, double armor, double agility, double damage, int slotId);
	/**
	 * @brief Dostêp do struktury z statystykami przedmiotu
	 *
	 * @return struct statistics zawieraj¹c¹ statystyki przedmiotu
	 */
	struct statistics getStat();
	/**
	 * @brief Dostêp do rozmiaru przedmioru
	 *
	 * @return FloatRect bêd¹cy rozmiarem przedmiotu
	 */
	FloatRect getSize();
	/**
	 * @brief Dostêp do pozycji przedmiiotu
	 *
	 * @return Vector2f-bêd¹ce pozycja przedmiotu
	 */
	Vector2f getPos();
	/**
	 * @brief Ustawianie pozycji przedmiotu
	 *
	 * @param pos nowa pozycja
	 */
	void setPos(Vector2f pos);
	/**
	 * @brief Dostêp do nazwy przedmiotu
	 *
	 * @return std::string-bêd¹ce nazw¹ przedmiotu
	 */
	std::string getName();
	/**
	 * @brief Aktualizacja parametrów przedmiotu
	 *
	 */
	void update();
	/**
	 * @brief Wyœwietlanie prezedmiotu na ekranie
	 *
	 * @param target
	 */
	void render(RenderTarget* target);
};

