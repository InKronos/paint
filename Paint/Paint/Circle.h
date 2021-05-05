#pragma once
#include "SceneObject.h"
#include "EllipseShape.h"
class Circle :
    public SceneObject
{
    EllipseShape circle;
    sf::Vector2f startingPosition;
public:
    Circle(sf::Vector2f mousePosition, sf::Color color, int thickness, bool addFillColor);
    ~Circle();
    void draw(sf::RenderWindow& window);
    void update(sf::Vector2f mousePosition, bool isShiftPressed);
    
};

