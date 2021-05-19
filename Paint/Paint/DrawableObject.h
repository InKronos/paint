/**
 * @file DrawableObject.h
 * @brief plik zawiekaj¹cy klase DrawableObject która dziedziczy od SceneObject, jest ona baz¹ dla obiektów które da siê narysowaæ
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

