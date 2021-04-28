#include "Pen.h"

Pen::Pen(sf::Vector2f position, sf::Vector2f lastPostion, bool toDraw)
{
	//this->rectPen.setRadius(8);
	//this->rectPen.setPosition(position);
	//this->rectPen.setFillColor(sf::Color::Blue);
	std::cout << "Pen created" << std::endl;
	if (toDraw) {
		this->betweenCircle = sf::VertexArray(sf::Lines, 2);
		this->betweenCircle[0].color = sf::Color::Blue;
		this->betweenCircle[1].color = sf::Color::Blue;
		this->betweenCircle[0].position = lastPostion;
		this->betweenCircle[1].position = position;
	}
}

Pen::~Pen()
{
}

void Pen::draw(sf::RenderWindow& window)
{
	window.draw(this->rectPen);
	window.draw(this->betweenCircle);
}
