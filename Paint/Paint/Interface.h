#pragma once
#include "stdafx.h"

class Interface
{
	sf::RectangleShape mainBlock;
	bool isSaveWindow;
	sf::RectangleShape mainSaveBlock;
	sf::RectangleShape YesBlock;
	sf::RectangleShape NoBlock;
	
	sf::Text Information;
	sf::Font font;
	sf::Text FileName;

public:

	Interface();
	~Interface();
	void draw(sf::RenderWindow& window);
};

