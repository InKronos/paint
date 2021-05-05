#include "Brush.h"

Brush::Brush(sf::Vector2f position, sf::Color color, int thickness)
	: lastPosition(position), color(color), thickness(thickness)
{
	//sf::CircleShape circle(2.5);
	//circle.setPosition(position);
	//circle.setFillColor(color);
	//allCircleObjects.push_back(circle);
}

Brush::~Brush()
{
}

void Brush::update(sf::Vector2f mousePosition)
{
	Line betweenCircle(lastPosition, this->color, this->thickness);
	sf::CircleShape circle(this->thickness/2);
	circle.setPosition(sf::Vector2f(mousePosition.x, mousePosition.y));
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
