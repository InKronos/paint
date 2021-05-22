/**
 * @file BaseBlock.h
 * @brief plik zawiekaj¹cy klase Block która dziedziczy od SceneObject, jest baz¹ dla szablonu bloków
 */
#pragma once
#include "SceneObject.h"

 /** Klasa obiektu bazowego BaseBlock*/
class BaseBlock :
    public SceneObject
{
protected:
	sf::RectangleShape shape; ///< kszta³t bloku
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

	/** Funkcja ustawiaj¹ca teksture
	 * @param texture tekstura
	 */
	void setTexture(sf::Texture &texture);

	/** Funkcja sprawdzj¹ca czy blok jest naciœniêty
	 * @param  mousePosition pozycja myszki
	 * @return zmienna logiczna mówi¹ca czy blok jest naciœniêty
	 */
	bool isClicked(sf::Vector2f mousePosition);

	/** Funkcja ustawiaj¹ca obramowanie */
	void setOutLineColor();

	/** Funkcja ustawiaj¹ca usuwaj¹ca */
	void deleteOutLineColor();

	/** Funkcja do rysowania w oknie
	 * @param window okno do rysowania
	 */
	void draw(sf::RenderWindow& window);
};

