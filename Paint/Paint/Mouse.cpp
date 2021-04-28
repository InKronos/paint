#include "Mouse.h"

Mouse::Mouse() : type(drawType::Pen)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition();
	this->position = sf::Vector2f(0, 0);
}

Mouse::~Mouse()
{
}

void Mouse::update(sf::RenderWindow& window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	//std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
	this->position = sf::Vector2f(mousePosition.x, mousePosition.y);
}

sf::Vector2f Mouse::getPosition()
{
	return this->position;
}
