#include "Mouse.h"

Mouse::Mouse() : type(drawType::Pen), color(sf::Color::Blue)
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

void Mouse::setColor(sf::Color color)
{
	this->color = color;
}

drawType Mouse::getDrawType()
{
	return this->type;
}

void Mouse::setDrawType(drawType type)
{
	this->type = type;
}

sf::Color Mouse::getColor()
{
	return this->color;
}
