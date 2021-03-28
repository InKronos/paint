#include "Block.h"

Block::Block(sf::Vector2f position, sf::Vector2f size) 
{
	shape.setSize(size);
	shape.setPosition(position);
}

Block::~Block()
{
}

void Block::draw(sf::RenderWindow& window)
{
	window.draw(this->shape);
}
