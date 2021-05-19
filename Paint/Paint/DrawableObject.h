/**
 * @file DrawableObject.h
 * @brief plik zawiekaj�cy klase DrawableObject kt�ra dziedziczy od SceneObject, jest ona baz� dla obiekt�w kt�re da si� narysowa�
 */
#pragma once
#include "SceneObject.h"

 /** Klasa wirtualnego obiektu DrawableObject */
class DrawableObject :
    public SceneObject
{
public:
    /** wirtualna funkcja do aktualizowania obiektu
     * @param mousePosition pozycja myszki
     */
    void virtual update(sf::Vector2f mousePosition) = 0;
};

