#include "Pen.h"

Pen::Pen(sf::Vector2f position)
{
	this->rectPen.setSize({ 5, 5 });
	this->rectPen.setPosition(position);
	this->rectPen.setFillColor(sf::Color::Blue);
	std::cout << "Pen created" << std::endl;
}

Pen::~Pen()
{
}

void Pen::draw(sf::RenderWindow& window)
{
	window.draw(this->rectPen);
}
