#pragma once
#include "DrawableObject.h"
#include "stdafx.h"


class SceneObject;

class Pen : public DrawableObject
{
	std::vector<sf::VertexArray> allPenObjects;
	sf::Vector2f lastposition;
	sf::Color color;
public:
	
	Pen(sf::Vector2f position, sf::Color color);
	~Pen();
	void update(sf::Vector2f mousePosition);
	void draw(sf::RenderWindow& window);

};

