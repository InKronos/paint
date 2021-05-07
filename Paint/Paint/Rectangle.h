#pragma once
#include "stdafx.h"
#include "DrawableObject.h"

class Rectangle : public DrawableObject
{
private:
	sf::RectangleShape rect;
	sf::Vector2f startingPostion;
public:
	Rectangle(sf::Vector2f mousePosition, sf::Color color, int thickness, bool addFillColor);
	~Rectangle();

	void draw(sf::RenderWindow& window);
	void update(sf::Vector2f mousePosition);
	void updateWithShift(sf::Vector2f mousePosition);
};

