#include "FuncionalBlock.h"

FuncionalBlock::FuncionalBlock(sf::Vector2f position, sf::Vector2f size, drawType _type) : Block(position, size)
{
	this->dType = _type;
	this->shape.setFillColor(sf::Color::Black);
	this->shape.setOutlineThickness(3);
	this->shape.setOutlineColor(sf::Color::Black);
}

FuncionalBlock::~FuncionalBlock()
{
}

drawType FuncionalBlock::getDrawType()
{
	return this->dType;
}
