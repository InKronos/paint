#pragma once
#include "stdafx.h"

class Pen
{
	sf::RectangleShape rectPen;
public:
	Pen(sf::Vector2f position);
	~Pen();
	void draw(sf::RenderWindow& window);

};

