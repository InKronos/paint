#include "Circle.h"

Circle::Circle(sf::Vector2f mousePosition, sf::Color color, int thickness, bool addFillColor)
	: startingPosition(mousePosition)
{
	this->circle.setRadius(sf::Vector2f({ 1, 1 }));
	this->circle.setPosition(mousePosition);
	if (addFillColor)
		this->circle.setFillColor(color);
	else
		this->circle.setFillColor(sf::Color::Transparent);

	this->circle.setOutlineColor(color);
	this->circle.setOutlineThickness(-thickness);
}

Circle::~Circle()
{
}

void Circle::draw(sf::RenderWindow& window)
{
	window.draw(this->circle);
}

void Circle::update(sf::Vector2f mousePosition)
{
	this->circle.setRadius({ (mousePosition.x - this->startingPosition.x) / 2, (mousePosition.y - this->startingPosition.y) / 2 });
}

void Circle::updateWithShift(sf::Vector2f mousePosition)
{
	if (mousePosition.x - this->startingPosition.x > 0) {
		if (mousePosition.y - this->startingPosition.y > 0) {
			if (mousePosition.y - this->startingPosition.y > mousePosition.x - this->startingPosition.x)
				this->circle.setRadius({ (mousePosition.y - this->startingPosition.y) / 2, (mousePosition.y - this->startingPosition.y) / 2 });
			else
				this->circle.setRadius({ (mousePosition.x - this->startingPosition.x) / 2, (mousePosition.x - this->startingPosition.x) / 2 });
		}
		else {
			if (-(mousePosition.y - this->startingPosition.y) > mousePosition.x - this->startingPosition.x)
				this->circle.setRadius({ -(mousePosition.y - this->startingPosition.y) / 2, (mousePosition.y - this->startingPosition.y) / 2 });
			else
				this->circle.setRadius({ (mousePosition.x - this->startingPosition.x) / 2, (mousePosition.x - this->startingPosition.x) / 2 });
		}
	}
	else {
		if (mousePosition.y - this->startingPosition.y > 0) {
			if (mousePosition.y - this->startingPosition.y > -(mousePosition.x - this->startingPosition.x))
				this->circle.setRadius({ -(mousePosition.y - this->startingPosition.y) / 2, (mousePosition.y - this->startingPosition.y) / 2 });
			else
				this->circle.setRadius({ (mousePosition.x - this->startingPosition.x) / 2, -(mousePosition.x - this->startingPosition.x) / 2 });
		}
		if (mousePosition.y - this->startingPosition.y < 0) {
			if (-(mousePosition.y - this->startingPosition.y) > -(mousePosition.x - this->startingPosition.x))
				this->circle.setRadius({ (mousePosition.y - this->startingPosition.y) / 2, (mousePosition.y - this->startingPosition.y) / 2 });
			else
				this->circle.setRadius({ (mousePosition.x - this->startingPosition.x) / 2, -(mousePosition.x - this->startingPosition.x) / 2 });
		}
	}
}
