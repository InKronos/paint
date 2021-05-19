/**
 * @file Pen.h
 * @brief plik zawiekaj�cy klase Pen kt�ra dziedziczy od DrawableObject
 */
#pragma once
#include "DrawableObject.h"
#include "stdafx.h"


 /** Klasa obiektu Rectangle b�d�cego d�ugopisem */
class Pen : public DrawableObject
{
	std::vector<sf::VertexArray> allPenObjects; ///< kontener kt�ry przechowuje wszystkie linie kt�re s� ju� utworzone
	sf::Vector2f lastposition; ///< ostatnia zanotowana pozycja
	sf::Color color; ///< kolor d�ugopisu
public:
	/** Konstruktor klasy Pen
	 * @param position pozycja na kt�rej pierwszy obiekt ma by� utworzony
	 * @param color kolor lini
	 */
	Pen(sf::Vector2f position, sf::Color color);

	/** Dekonstruktor klasy Pen */
	~Pen();

	/** Funkcja kt�ra aktualizuje gdzie lina ma by� narysowana 
	 * @param mousePosition aktualna pozycja myszki
	 */
	void update(sf::Vector2f mousePosition);

	/** Funkcja do rysowania w oknie
	 * @param window okno do rysowania
	 */
	void draw(sf::RenderWindow& window);

};

