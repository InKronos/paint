#include "Rectangle.h"

Rectangle::Rectangle(sf::Vector2f mousePosition, sf::Color color, int thickness, bool addFillColor) : startingPostion(mousePosition)
{
	this->rect.setSize(sf::Vector2f({ 1, 1 }));
	this->rect.setPosition(sf::Vector2f(mousePosition.x - 5, mousePosition.y - 5));
	if (addFillColor)
		this->rect.setFillColor(color);
	else
		this->rect.setFillColor(sf::Color::Transparent);
	this->rect.setOutlineThickness(-thickness);
	this->rect.setOutlineColor(color);
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
	//std::cout << "Wielkosc X: " << mousePosition.x - this->startingPostion.x << " Wielko?? Y: " <<
}

void Rectangle::updateWithShift(sf::Vector2f mousePosition)
{
	if (mousePosition.x - this->startingPostion.x > 0) {
		if (mousePosition.y - this->startingPostion.y > 0) {
			if (mousePosition.y - this->startingPostion.y > mousePosition.x - this->startingPostion.x)
				this->rect.setSize({ mousePosition.y - this->startingPostion.y, mousePosition.y - this->startingPostion.y });
			else
				this->rect.setSize({ mousePosition.x - this->startingPostion.x, mousePosition.x - this->startingPostion.x });
		}
		else {
			if (-(mousePosition.y - this->startingPostion.y) > mousePosition.x - this->startingPostion.x)
				this->rect.setSize({ -(mousePosition.y - this->startingPostion.y), mousePosition.y - this->startingPostion.y });
			else
				this->rect.setSize({ mousePosition.x - this->startingPostion.x, -(mousePosition.x - this->startingPostion.x) });
		}
	}
	else {
		if (mousePosition.y - this->startingPostion.y > 0) {
			if (mousePosition.y - this->startingPostion.y > -(mousePosition.x - this->startingPostion.x))
				this->rect.setSize({ -(mousePosition.y - this->startingPostion.y), mousePosition.y - this->startingPostion.y });
			else
				this->rect.setSize({ mousePosition.x - this->startingPostion.x, -(mousePosition.x - this->startingPostion.x) });
		}
		if (mousePosition.y - this->startingPostion.y < 0) {
			if (-(mousePosition.y - this->startingPostion.y) > -(mousePosition.x - this->startingPostion.x))
				this->rect.setSize({ mousePosition.y - this->startingPostion.y, mousePosition.y - this->startingPostion.y });
			else
				this->rect.setSize({ mousePosition.x - this->startingPostion.x, -(mousePosition.x - this->startingPostion.x) });
		}
	}
}


