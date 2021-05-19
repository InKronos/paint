/**
 * @file class Mouse.h
 * @brief plik zawiekaj¹cy klase Mouse która obs³uguje myszke, plik równie¿ zawiera enum class drawType 
 */
#pragma once
#include "stdafx.h"

 /** Klasa enum tego co ma byæ narysowane */
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
	drawType type; ///< typ obiektu który nale¿y narysowaæ
	sf::Color color; ///< kolor obiektu który nale¿y narysowaæ
	int thickness; ///< gruboœæ obiektu który nale¿y narysowaæ
	bool addFillColor; ///< zmienna logiczna mówi¹ca czy obiekt narysowany ma byæ wype³niony
public:
	/** Konstruktor klasy Mouse */
	Mouse();

	/** Dekonstruktor klasy Mouse */
	~Mouse();

	/** Funkcja która aktualizuje gdzie jest myszka w oknie
	 * @param window okno 
	 */
	void update(sf::RenderWindow& window);
	
	/** Getter który zwraca pozycje myszki 
	 * @return pozycja myszki
	 */
	sf::Vector2f getPosition();

	/** Setter który aktualizuje kolor
	 * @param color kolor
	 */
	void setColor(sf::Color color);

	/** Getter który zwraca jaki ma byæ typ obiektu do narysowania
	 * @return typ obiektu do narysowania
	 */
	drawType getDrawType();

	/** Setter który aktualizuje typ obiektu do narysowania 
	 * @param type typ obiektu do narysowania
	 */
	void setDrawType(drawType type);

	/** Getter który zwraca jaki ma byæ kolor obiektu do narysowania
	 * @return kolor obiektu do narysowania
	 */
	sf::Color getColor();

	/** Setter który aktualizuje gruboœæ obiektu do narysowania
	 * @param thickness  gruboœæ obiektu do narysowania
	 */
	void changeThickness(int thickness);

	/** Getter który zwraca jaka ma byæ gruboœæ obiektu do narysowania
	 * @return gruboœæ obiektu do narysowania
	 */
	int getThickness();

	/** Setter który aktualizuje zmienn¹ logiczn¹, która mówi czy obiekt ma byæ wype³niony
	 * @param fillColor zmienn¹ logiczna, która mówi czy obiekt ma byæ wype³niony
	 */
	void setAddFillColor(bool fillColor);

	/** Getter który zwraca zmienn¹ logiczn¹, która mówi czy obiekt ma byæ wype³niony
	 * @return zmienna logiczna która mówi czy obiekt ma byæ wype³niony
	 */
	bool getAddFillColor();

	/** Funkcja do rysowania w oknie
	 * @param window okno do rysowania
	 */
	void draw(sf::RenderWindow& window);

};

