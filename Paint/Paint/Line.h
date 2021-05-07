#pragma once
#include "DrawableObject.h"
class Line :
    public DrawableObject
{
    sf::RectangleShape line;
    sf::Vector2f startingPosition;
    int thickness;
public:
    Line(sf::Vector2f mousePosition, sf::Color color, int thickness);
    ~Line();
    void draw(sf::RenderWindow& window);
    void update(sf::Vector2f mousePosition); 
};

