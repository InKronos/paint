/**
 * @file Line.h
 * @brief plik zawiekaj�cy klase Line kt�ra dziedziczy od DrawableObject
 */
#pragma once
#include "DrawableObject.h"

 /** Klasa obiektu Line */
class Line :
    public DrawableObject
{
    sf::RectangleShape line; ///< Linia do narysowania
    sf::Vector2f startingPosition; ///< pozycja startowa
    int thickness; ///< grubo�� lini
public:
    /** Konstruktor klasy Line
     * @param mousePosition pozycja myszki
     * @param color kolor lini
     * @param thickness grubo�� lini
     */
    Line(sf::Vector2f mousePosition, sf::Color color, int thickness);
    
    /** Dekonstruktor klasy Line */
    ~Line();

    /** Funkcja do rysowania w oknie
     * @param window okno do rysowania
     */
    void draw(sf::RenderWindow& window);

    /** Funkcja kt�ra aktualizuje linie
     * @param mousePosition aktualna pozycja myszki
     */
    void update(sf::Vector2f mousePosition); 
};

