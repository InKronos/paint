#include "Brush.h"

Brush::Brush(sf::Vector2f position, sf::Color color, int thickness)
	: lastPosition(position), color(color), thickness(thickness)
{
}

Brush::~Brush()
{
	allCircleObjects.clear();
	allBetweenCircle.clear();
}

void Brush::update(sf::Vector2f mousePosition)
{
	Line betweenCircle(lastPosition, this->color, this->thickness);
	sf::CircleShape circle(this->thickness/2);
	circle.setPosition(sf::Vector2f(mousePosition.x - this->thickness / 2, mousePosition.y - this->thickness / 2));
	circle.setFillColor(color);
	betweenCircle.update(mousePosition);
	this->lastPosition = mousePosition;
	allCircleObjects.push_back(circle);
	allBetweenCircle.push_back(betweenCircle);
}




void Brush::draw(sf::RenderWindow& window)
{
	for (auto i = 0; i < allBetweenCircle.size(); i++)
	{
		allBetweenCircle[i].draw(window);
	}
	for (auto i = 0; i < allCircleObjects.size(); i++)
	{
		window.draw(allCircleObjects[i]);
	}
}
