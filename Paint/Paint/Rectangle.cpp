#include "Rectangle.h"

Rectangle::Rectangle(sf::Vector2f mousePosition, sf::Color color) : startingPostion(mousePosition)
{
	this->rect.setSize(sf::Vector2f({ 1, 1 }));
	this->rect.setPosition(mousePosition);
	this->rect.setFillColor(color);
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
	this->rect.setSize({ mousePosition.x - this->startingPostion.x, mousePosition.y - this->startingPostion.y });
	//std::cout << "Wielkosc X: " << mousePosition.x - this->startingPostion.x << " Wielkoœæ Y: " <<
}
