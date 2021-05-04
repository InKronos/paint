#include "Line.h"

#define PI 3.14159265

Line::Line(sf::Vector2f mousePosition, sf::Color color)
	: startingPosition(mousePosition)
{
	line.setPosition(sf::Vector2f(mousePosition.x, mousePosition.y));
	line.setSize({ 1, 1 });
	line.setFillColor(color);
}

Line::~Line()
{
}

void Line::draw(sf::RenderWindow& window)
{
	window.draw(this->line);
}

void Line::update(sf::Vector2f mousePosition)
{
	long double x = abs(mousePosition.x - startingPosition.x);
	long double y = abs(mousePosition.y - startingPosition.y);
	unsigned int size = floor(sqrt(pow(abs(x), 2) + pow(abs(y), 2)));
	line.setSize(sf::Vector2f(5, size));

	long double degrees = 0;
	if (y != 0) {
		
		degrees = atan(x / y) * 180 / PI;
	}
	
	if (mousePosition.x - startingPosition.x < 0 && mousePosition.y - startingPosition.y <= 0) {
		if (degrees == 0)
			degrees = -90;
		else
			degrees += 180;
		degrees *= -1;
	}
	else if ((mousePosition.x - startingPosition.x) > 0 && (mousePosition.y - startingPosition.y) >= 0) {
		if (degrees == 0)
			degrees = 90;
		degrees *= -1;
	}
	if (mousePosition.x - startingPosition.x >= 0 && mousePosition.y - startingPosition.y < 0) {

		degrees += 180;
	}
	line.setRotation(degrees);
}
