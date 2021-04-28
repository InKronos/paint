#pragma once
#include "stdafx.h"
#include "SceneObject.h"

class Rectangle : public SceneObject
{
private:
	sf::RectangleShape rect;
	sf::Vector2f startingPostion;
public:
	Rectangle(sf::Vector2f mousePosition);
	~Rectangle();

	void draw(sf::RenderWindow& window);
	void update(sf::Vector2f mousePosition);
};

