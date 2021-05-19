/**
 * @file class Mouse.h
 * @brief plik zawiekaj�cy klase Mouse kt�ra obs�uguje myszke, plik r�wnie� zawiera enum class drawType 
 */
#pragma once
#include "stdafx.h"

 /** Klasa enum tego co ma by� narysowane */
enum class drawType
{
	Pen,
	Rectangle,
	Circle,
	Line,
	Brush
};

/** Klasa myszki */
class Mouse
{
private:
	sf::Vector2f position; ///< pozycja myszki
	sf::CircleShape MouseImage; ///< obiekt myszki do narysowania
	drawType type; ///< typ obiektu kt�ry nale�y narysowa�
	sf::Color color; ///< kolor obiektu kt�ry nale�y narysowa�
	int thickness; ///< grubo�� obiektu kt�ry nale�y narysowa�
	bool addFillColor; ///< zmienna logiczna m�wi�ca czy obiekt narysowany ma by� wype�niony
public:
	/** Konstruktor klasy Mouse */
	Mouse();

	/** Dekonstruktor klasy Mouse */
	~Mouse();

	/** Funkcja kt�ra aktualizuje gdzie jest myszka w oknie
	 * @param window okno 
	 */
	void update(sf::RenderWindow& window);
	
	/** Getter kt�ry zwraca pozycje myszki 
	 * @return pozycja myszki
	 */
	sf::Vector2f getPosition();

	/** Setter kt�ry aktualizuje kolor
	 * @param color kolor
	 */
	void setColor(sf::Color color);

	/** Getter kt�ry zwraca jaki ma by� typ obiektu do narysowania
	 * @return typ obiektu do narysowania
	 */
	drawType getDrawType();

	/** Setter kt�ry aktualizuje typ obiektu do narysowania 
	 * @param type typ obiektu do narysowania
	 */
	void setDrawType(drawType type);

	/** Getter kt�ry zwraca jaki ma by� kolor obiektu do narysowania
	 * @return kolor obiektu do narysowania
	 */
	sf::Color getColor();

	/** Setter kt�ry aktualizuje grubo�� obiektu do narysowania
	 * @param thickness  grubo�� obiektu do narysowania
	 */
	void changeThickness(int thickness);

	/** Getter kt�ry zwraca jaka ma by� grubo�� obiektu do narysowania
	 * @return grubo�� obiektu do narysowania
	 */
	int getThickness();

	/** Setter kt�ry aktualizuje zmienn� logiczn�, kt�ra m�wi czy obiekt ma by� wype�niony
	 * @param fillColor zmienn� logiczna, kt�ra m�wi czy obiekt ma by� wype�niony
	 */
	void setAddFillColor(bool fillColor);

	/** Getter kt�ry zwraca zmienn� logiczn�, kt�ra m�wi czy obiekt ma by� wype�niony
	 * @return zmienna logiczna kt�ra m�wi czy obiekt ma by� wype�niony
	 */
	bool getAddFillColor();

	/** Funkcja do rysowania w oknie
	 * @param window okno do rysowania
	 */
	void draw(sf::RenderWindow& window);

};

