/**
 * @file Rectangle.h
 * @brief plik zawiekaj�cy klase Rectangle kt�ra dziedziczy od DrawableObject
 */
#pragma once
#include "stdafx.h"
#include "DrawableObject.h"


 /** Klasa obiektu Rectangle b�d�cego prostok�tem */
class Rectangle : public DrawableObject
{
private:
	sf::RectangleShape rect; ///< Obiekt prostok�ta
	sf::Vector2f startingPostion; ///< Pozycja startowa
public:
	/** Konstruktor klasy Rectangle
	 * @param mousePosition pozycja myszki
	 * @param color kolor prostok�ta
	 * @param thickness rozmiar obramowania prostok�ta
	 * @param addFillColor zmienna logiczna kt�ra odpowada za to czy prostok�t ma by� wype�niony
	 */
	Rectangle(sf::Vector2f mousePosition, sf::Color color, int thickness, bool addFillColor);

	/** Dekonstruktor klasy Rectangle */
	~Rectangle();

	/** Funkcja do rysowania w oknie
	 * @param window okno do rysowania
	 */
	void draw(sf::RenderWindow& window);

	/** Funkcja kt�ra aktualizuje rozmiar prostok�ta
	 * @param mousePosition aktualna pozycja myszki
	 */
	void update(sf::Vector2f mousePosition);

	/** Funkcja kt�ra aktualizuje rozmiar prostok�ta, kiedy przycisk Shift jest nacisni�ty
	 * @param mousePosition aktualna pozycja myszki
	 */
	void updateWithShift(sf::Vector2f mousePosition);
};

