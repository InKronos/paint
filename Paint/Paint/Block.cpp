#include "Block.h"

Block::Block(sf::Vector2f position, sf::Vector2f size) : size(size), position(position)
{
	shape.setSize(size);
	shape.setPosition(position);
}

Block::~Block()
{
}

bool Block::isClicked(sf::Vector2f mousePosition)
{
	if (mousePosition.x > this->position.x && mousePosition.y > this->position.y && mousePosition.x < (this->position.x + this->size.x) && mousePosition.y < (this->position.y + this->size.y))
		return true;
	return false;
}

void Block::setOutLineColor()
{
	this->shape.setOutlineColor(sf::Color::Transparent);
}

void Block::deleteOutLineColor()
{
	this->shape.setOutlineColor(this->shape.getFillColor());
}


void Block::draw(sf::RenderWindow& window)
{
	window.draw(this->shape);
}
