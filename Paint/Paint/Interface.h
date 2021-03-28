#pragma once
#include "stdafx.h"

class Interface
{
	sf::RectangleShape mainBlock;
	

public:

	Interface();
	~Interface();
	void draw(sf::RenderWindow& window) const;
};

