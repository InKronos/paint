#pragma once
#include "SceneObject.h"
#include "Line.h"
class Brush :
    public SceneObject
{
    std::vector<Line> allBetweenCircle;
    std::vector<sf::CircleShape> allCircleObjects;
    sf::Color color;
    sf::Vector2f lastPosition;
    int thickness;
public:
    Brush(sf::Vector2f position,  sf::Color color, int thickness);
    ~Brush();

    void update(sf::Vector2f mousePosition);

    void draw(sf::RenderWindow& window);
};

