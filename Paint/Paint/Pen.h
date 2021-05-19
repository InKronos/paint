/**
 * @file Pen.h
 * @brief plik zawiekaj¹cy klase Pen która dziedziczy od DrawableObject
 */
#pragma once
#include "DrawableObject.h"
#include "stdafx.h"


 /** Klasa obiektu Rectangle bêd¹cego d³ugopisem */
class Pen : public DrawableObject
{
	std::vector<sf::VertexArray> allPenObjects; ///< kontener który przechowuje wszystkie linie które s¹ ju¿ utworzone
	sf::Vector2f lastposition; ///< ostatnia zanotowana pozycja
	sf::Color color; ///< kolor d³ugopisu
public:
	/** Konstruktor klasy Pen
	 * @param position pozycja na której pierwszy obiekt ma byæ utworzony
	 * @param color kolor lini
	 */
	Pen(sf::Vector2f position, sf::Color color);

	/** Dekonstruktor klasy Pen */
	~Pen();

	/** Funkcja która aktualizuje gdzie lina ma byæ narysowana 
	 * @param mousePosition aktualna pozycja myszki
	 */
	void update(sf::Vector2f mousePosition);

	/** Funkcja do rysowania w oknie
	 * @param window okno do rysowania
	 */
	void draw(sf::RenderWindow& window);

};

