#include "ColorBlock.h"


ColorBlock::ColorBlock(sf::Vector2f position, sf::Vector2f size, sf::Color color) : Block(position, size)
{
	this->shape.setFillColor(color);
	this->shape.setOutlineThickness(3);
	this->shape.setOutlineColor(color);
}

ColorBlock::~ColorBlock()
{
}

sf::Color ColorBlock::getColor()
{
	return this->shape.getFillColor();
}

void ColorBlock::setOutLineColor()
{
	this->shape.setOutlineColor(sf::Color::Color(100, 100, 100));
	std::cout << "jest zaznaczenie" << std::endl;
}

void ColorBlock::deleteOutLineColor()
{
	this->shape.setOutlineColor(this->getColor());
	std::cout << "nie ma zaznaczenia" << std::endl;
}
