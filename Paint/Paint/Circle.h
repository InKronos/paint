/**
 * @file Circle.h
 * @brief plik zawiekaj�cy klase Circle kt�ra dziedziczy od DrawableObject
 */
#pragma once
#include "DrawableObject.h"
#include "EllipseShape.h"
 /** Klasa obiektu Rectangle b�d�cego elips� */
class Circle :
    public DrawableObject
{
    EllipseShape circle; ///< Obiekt elipsy
    sf::Vector2f startingPosition; ///< Pozycja startowa
public:
    /** Konstruktor klasy Circle
     * @param mousePosition pozycja myszki
     * @param color kolor elipsy
     * @param thickness rozmiar obramowania elipsy
     * @param addFillColor zmienna logiczna kt�ra odpowada za to czy elipsa ma by� wype�niona
     */
    Circle(sf::Vector2f mousePosition, sf::Color color, int thickness, bool addFillColor);

    /** Dekonstruktor klasy Circle */
    ~Circle();

    /** Funkcja do rysowania w oknie
     * @param window okno do rysowania
     */
    void draw(sf::RenderWindow& window);

    /** Funkcja kt�ra aktualizuje rozmiar elipsy
     * @param mousePosition aktualna pozycja myszki
     */
    void update(sf::Vector2f mousePosition);

    /** Funkcja kt�ra aktualizuje rozmiar elipsy, kiedy przycisk Shift jest nacisni�ty
     * @param mousePosition aktualna pozycja myszki
     */
    void updateWithShift(sf::Vector2f mousePosition);
};

