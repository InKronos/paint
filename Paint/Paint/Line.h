#pragma once
#include "SceneObject.h"
class Line :
    public SceneObject
{
    sf::RectangleShape line;
    sf::Vector2f startingPosition;
public:
    Line(sf::Vector2f mousePosition, sf::Color color);
    ~Line();
    void draw(sf::RenderWindow& window);
    void update(sf::Vector2f mousePosition); 
};

