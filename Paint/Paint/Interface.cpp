#include "Interface.h"

Interface::Interface()
{
	mainBlock.setSize(sf::Vector2f(800, 50));
	mainBlock.setFillColor(sf::Color::Color(100, 100, 100));
	mainBlock.setPosition(0, 0);
}

Interface::~Interface()
{
	
}

void Interface::draw(sf::RenderWindow& window) const
{
	window.draw(this->mainBlock);
}
