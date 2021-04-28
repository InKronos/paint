#include "Rectangle.h"

Rectangle::Rectangle(sf::Vector2f mousePosition) : startingPostion(mousePosition)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::draw(sf::RenderWindow& window)
{
	window.draw(this->rect);
}

void Rectangle::update(sf::Vector2f mousePosition) 
{

}
