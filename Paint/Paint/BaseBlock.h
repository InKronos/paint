/**
 * @file BaseBlock.h
 * @brief plik zawiekaj�cy klase Block kt�ra dziedziczy od SceneObject, jest baz� dla szablonu blok�w
 */
#pragma once
#include "SceneObject.h"

 /** Klasa obiektu bazowego BaseBlock*/
class BaseBlock :
    public SceneObject
{
protected:
	sf::RectangleShape shape; ///< kszta�t bloku
	sf::Vector2f position; ///< pozycja bloku
	sf::Vector2f size; ///< rozmiar bloku
public:
	/** Konstruktor klasy BaseBlock
	 * @param position pozycja bloku
	 * @param size rozmiar bloku
	 * @param color kolor bloku
	 */
	BaseBlock(sf::Vector2f position, sf::Vector2f size, sf::Color color);

	/** Dekonstruktor klasy Block */
	~BaseBlock();

	/** Funkcja ustawiaj�ca teksture
	 * @param texture tekstura
	 */
	void setTexture(sf::Texture &texture);

	/** Funkcja sprawdzj�ca czy blok jest naci�ni�ty
	 * @param  mousePosition pozycja myszki
	 * @return zmienna logiczna m�wi�ca czy blok jest naci�ni�ty
	 */
	bool isClicked(sf::Vector2f mousePosition);

	/** Funkcja ustawiaj�ca obramowanie */
	void setOutLineColor();

	/** Funkcja ustawiaj�ca usuwaj�ca */
	void deleteOutLineColor();

	/** Funkcja do rysowania w oknie
	 * @param window okno do rysowania
	 */
	void draw(sf::RenderWindow& window);
};

