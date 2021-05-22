#include "Mouse.h"

Mouse::Mouse()
	: type(drawType::Pen), color(sf::Color::Blue), thickness(3), addFillColor(false)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition();
	this->position = sf::Vector2f(0, 0);
	MouseImage.setFillColor(sf::Color::Color(255, 165, 0));
	MouseImage.setRadius(1);
}

Mouse::~Mouse()
{
}

void Mouse::update(sf::RenderWindow& window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	this->position = sf::Vector2f(mousePosition.x, mousePosition.y);
	
	if (this->type != drawType::Pen) {
		this->MouseImage.setPosition(sf::Vector2f(mousePosition.x - (this->thickness / 2), mousePosition.y - (this->thickness / 2)));
		this->MouseImage.setRadius(this->thickness / 2);
	}
		
	else {
		this->MouseImage.setPosition(sf::Vector2f(mousePosition.x - 1, mousePosition.y - 1));
		this->MouseImage.setRadius(1);
	}
		
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

void Mouse::changeThickness(int thickness)
{
	this->thickness += thickness;
	if (this->thickness > 15)
		this->thickness = 15;
	else if (this->thickness < 2)
		this->thickness = 2;
}

int Mouse::getThickness()
{
	return this->thickness;
}

void Mouse::setAddFillColor(bool fillColor)
{
	this->addFillColor = fillColor;
}

bool Mouse::getAddFillColor()
{
	return this->addFillColor;
}

void Mouse::draw(sf::RenderWindow& window)
{
	window.draw(this->MouseImage);
}


