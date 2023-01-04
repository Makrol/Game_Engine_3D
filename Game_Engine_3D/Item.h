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
 * @brief Klasa przedmiot�w dost�pnych w grze
 *
 */
class Item
{
private:
	Sprite body;/*!<Cia�o obiektu posiadaj�ce tekture wy�wietlane na ekranie>*/
	std::string name;/*!<Nazwa przedmiotu>*/

	struct statistics stat;/*!<Struktura z statystykami przedmiotu>*/
public:
	int slotId;/*!<Typ przedmiotu>*/
	/**
	 * @brief Konstruktor domy�lny obiektu
	 *
	 */
	Item();
	/**
	 * @brief Konstruktor inicjuj�cy warto�ciami obiekt
	 *
	 * @param tex wska�nik na teksture przedmiotu
	 * @param pos pozycja przedmiotu
	 * @param name nazwa przedmiotu
	 * @param armor parametr obronny
	 * @param agility parametr zwinnosci
	 * @param damage parametr ataku
	 * @param slotId typ przedmiotu
	 */
	Item(Texture* tex, Vector2f pos, std::string name, double armor, double agility, double damage, int slotId);
	/**
	 * @brief Dost�p do struktury z statystykami przedmiotu
	 *
	 * @return struct statistics zawieraj�c� statystyki przedmiotu
	 */
	struct statistics getStat();
	/**
	 * @brief Dost�p do rozmiaru przedmioru
	 *
	 * @return FloatRect b�d�cy rozmiarem przedmiotu
	 */
	FloatRect getSize();
	/**
	 * @brief Dost�p do pozycji przedmiiotu
	 *
	 * @return Vector2f-b�d�ce pozycja przedmiotu
	 */
	Vector2f getPos();
	/**
	 * @brief Ustawianie pozycji przedmiotu
	 *
	 * @param pos nowa pozycja
	 */
	void setPos(Vector2f pos);
	/**
	 * @brief Dost�p do nazwy przedmiotu
	 *
	 * @return std::string-b�d�ce nazw� przedmiotu
	 */
	std::string getName();
	/**
	 * @brief Aktualizacja parametr�w przedmiotu
	 *
	 */
	void update();
	/**
	 * @brief Wy�wietlanie prezedmiotu na ekranie
	 *
	 * @param target
	 */
	void render(RenderTarget* target);
};

