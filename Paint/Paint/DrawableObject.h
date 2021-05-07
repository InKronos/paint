#pragma once
#include "SceneObject.h"
class DrawableObject :
    public SceneObject
{
public:
    void virtual update(sf::Vector2f mousePosition) = 0;
};

