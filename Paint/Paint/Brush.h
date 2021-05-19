/**
 * @file Brush.h
 * @brief plik zawiekaj¹cy klase Brush która dziedziczy od DrawableObject
 */
#pragma once
#include "DrawableObject.h"
#include "Line.h"

 /** Klasa obiektu Brush */
class Brush :
    public DrawableObject
{
    std::vector<Line> allBetweenCircle; ///< wektor zawieraj¹cy wszystkie linie pomiêdzy ko³i
    std::vector<sf::CircleShape> allCircleObjects; ///<  wektor zawieraj¹cy wszystkie ko³a
    sf::Color color; ///< kolor pêdzla
    sf::Vector2f lastPosition; ///< ostatnia pozycja
    int thickness; ///< gruboœæ pêdzla
public:
    /** Konstruktor klasy Brush
     * @param position pozycja na której pierwszy obiekt ma byæ utworzony
     * @param color kolor pêdzla
     * @param thickness gruboœæ pêdzla
     */
    Brush(sf::Vector2f position,  sf::Color color, int thickness);

    /** Dekonstruktor klasy Brush */
    ~Brush();

    /** Funkcja która aktualizuje gdzie pêdzel ma byæ narysowany
     * @param mousePosition aktualna pozycja myszki
     */
    void update(sf::Vector2f mousePosition);

    /** Funkcja do rysowania w oknie
     * @param window okno do rysowania
     */
    void draw(sf::RenderWindow& window);
};

