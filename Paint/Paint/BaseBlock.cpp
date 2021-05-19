#include "BaseBlock.h"

BaseBlock::BaseBlock(sf::Vector2f position, sf::Vector2f size, sf::Color color) : position(position), size(size)
{
	shape.setSize(size);
	shape.setPosition(position);
	shape.setFillColor(color);
	shape.setOutlineThickness(3);
	shape.setOutlineColor(this->shape.getFillColor());
}

BaseBlock::~BaseBlock()
{
}

void BaseBlock::setTexture(sf::Texture &texture)
{
	this->shape.setTexture(&texture);
}

bool BaseBlock::isClicked(sf::Vector2f mousePosition)
{
	if (mousePosition.x > this->position.x && mousePosition.y > this->position.y && mousePosition.x < (this->position.x + this->size.x) && mousePosition.y < (this->position.y + this->size.y))
		return true;
	return false;
}

void BaseBlock::setOutLineColor()
{
	this->shape.setOutlineColor(sf::Color::Transparent);
}

void BaseBlock::deleteOutLineColor()
{
	this->shape.setOutlineColor(this->shape.getFillColor());
}



void BaseBlock::draw(sf::RenderWindow& window)
{
	
	window.draw(this->shape);
}
