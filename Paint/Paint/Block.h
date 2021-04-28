#pragma once
#include "stdafx.h"
#include "SceneObject.h"

class Block : public SceneObject
{
protected:
	sf::RectangleShape shape;
	sf::Vector2f position;
	sf::Vector2f size;

public:
	Block(sf::Vector2f position, sf::Vector2f size);
	~Block();
	bool isClicked(sf::Vector2f mousePosition);
	void draw(sf::RenderWindow& window);
};

