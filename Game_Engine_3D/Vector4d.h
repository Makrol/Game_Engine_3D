#pragma once
/**
 * @brief Przechowuje wspó³rzêdne dwóch punktów
 */
class Vector4d
{
public:
	/**
	 * @brief Wektor 4d
	 *
	 * \param px1 Wspó³rzêdna x dla punktu 1
	 * \param py1 Wspó³rzêdna y dla punktu 1
	 * \param px2 Wspó³rzêdna x dla punktu 2
	 * \param py2 Wspó³rzêdna y dla punktu 2
	 */
	Vector4d(int px1, int py1, int px2, int py2);

	int px1;/*!< Wspó³rzêdna x dla punktu 1>*/
	int py1;/*!<>*/
	int px2;/*!<>*/
	int py2;/*!<>*/

	/**
	 * @brief Setter wektor
	 *
	 * \param px1 Ustawia wspó³rzêdn¹ x dla punktu 1
	 * \param py1 Ustawia wspó³rzêdn¹ y dla punktu 1
	 * \param px2 Ustawia wspó³rzêdn¹ x dla punktu 2
	 * \param py2 Ustawia wspó³rzêdn¹ y dla punktu 2
	 */
	void setValues(int px1, int py1, int px2, int py2);

};