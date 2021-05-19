/**
 * @file Brush.h
 * @brief plik zawiekaj�cy klase Brush kt�ra dziedziczy od DrawableObject
 */
#pragma once
#include "DrawableObject.h"
#include "Line.h"

 /** Klasa obiektu Brush */
class Brush :
    public DrawableObject
{
    std::vector<Line> allBetweenCircle; ///< wektor zawieraj�cy wszystkie linie pomi�dzy ko�i
    std::vector<sf::CircleShape> allCircleObjects; ///<  wektor zawieraj�cy wszystkie ko�a
    sf::Color color; ///< kolor p�dzla
    sf::Vector2f lastPosition; ///< ostatnia pozycja
    int thickness; ///< grubo�� p�dzla
public:
    /** Konstruktor klasy Brush
     * @param position pozycja na kt�rej pierwszy obiekt ma by� utworzony
     * @param color kolor p�dzla
     * @param thickness grubo�� p�dzla
     */
    Brush(sf::Vector2f position,  sf::Color color, int thickness);

    /** Dekonstruktor klasy Brush */
    ~Brush();

    /** Funkcja kt�ra aktualizuje gdzie p�dzel ma by� narysowany
     * @param mousePosition aktualna pozycja myszki
     */
    void update(sf::Vector2f mousePosition);

    /** Funkcja do rysowania w oknie
     * @param window okno do rysowania
     */
    void draw(sf::RenderWindow& window);
};

