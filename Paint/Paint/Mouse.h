#pragma once
#include "stdafx.h"

enum class drawType
{
	Pen,
	Rectangle
};


class Mouse
{
private:
	sf::Vector2f position;
	drawType type;
	sf::Color color;

public:
	Mouse();
	~Mouse();
	void update(sf::RenderWindow& window);
	//void drawObjects(sf::)
	sf::Vector2f getPosition();
	void setColor(sf::Color color);
	sf::Color getColor();
};

