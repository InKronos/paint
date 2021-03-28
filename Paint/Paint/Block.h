#pragma once
#include "stdafx.h"

class Block
{
protected:
	sf::RectangleShape shape;


public:
	Block(sf::Vector2f position, sf::Vector2f size);
	~Block();
	void draw(sf::RenderWindow& window);
};

