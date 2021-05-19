/**
 * @file Rectangle.h
 * @brief plik zawiekaj¹cy klase Rectangle która dziedziczy od DrawableObject
 */
#pragma once
#include "stdafx.h"
#include "DrawableObject.h"


 /** Klasa obiektu Rectangle bêd¹cego prostok¹tem */
class Rectangle : public DrawableObject
{
private:
	sf::RectangleShape rect; ///< Obiekt prostok¹ta
	sf::Vector2f startingPostion; ///< Pozycja startowa
public:
	/** Konstruktor klasy Rectangle
	 * @param mousePosition pozycja myszki
	 * @param color kolor prostok¹ta
	 * @param thickness rozmiar obramowania prostok¹ta
	 * @param addFillColor zmienna logiczna która odpowada za to czy prostok¹t ma byæ wype³niony
	 */
	Rectangle(sf::Vector2f mousePosition, sf::Color color, int thickness, bool addFillColor);

	/** Dekonstruktor klasy Rectangle */
	~Rectangle();

	/** Funkcja do rysowania w oknie
	 * @param window okno do rysowania
	 */
	void draw(sf::RenderWindow& window);

	/** Funkcja która aktualizuje rozmiar prostok¹ta
	 * @param mousePosition aktualna pozycja myszki
	 */
	void update(sf::Vector2f mousePosition);

	/** Funkcja która aktualizuje rozmiar prostok¹ta, kiedy przycisk Shift jest nacisniêty
	 * @param mousePosition aktualna pozycja myszki
	 */
	void updateWithShift(sf::Vector2f mousePosition);
};

