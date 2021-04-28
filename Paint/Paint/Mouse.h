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

public:
	Mouse();
	~Mouse();
	void update(sf::RenderWindow& window);
	//void drawObjects(sf::)
	sf::Vector2f getPosition();
};

