#include "Pen.h"

Pen::Pen(sf::Vector2f position, sf::Color color)
	: color(color), lastposition(position)
{
	sf::VertexArray pixel(sf::Lines, 2);
	pixel[0].color = color;
	pixel[1].color = color;
	pixel[0].position = position;
	pixel[1].position = sf::Vector2f(position.x, position.y + 1);
	this->allPenObjects.push_back(pixel);
}
Pen::~Pen()
{
	allPenObjects.clear();
}

void Pen::update(sf::Vector2f mousePosition)
{
	sf::VertexArray line(sf::Lines, 2);
	line[0].color = color;
	line[1].color = color;
	line[0].position = lastposition;
	line[1].position = mousePosition;
	this->lastposition = mousePosition;
	this->allPenObjects.push_back(line);
}


void Pen::draw(sf::RenderWindow& window)
{
	for(auto i = 0; i < allPenObjects.size(); i++)
		window.draw(allPenObjects[i]);
}
