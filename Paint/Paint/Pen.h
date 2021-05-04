#pragma once
#include "SceneObject.h"
#include "stdafx.h"
#include <SFML/Graphics.hpp>


class SceneObject;

class Pen : public SceneObject
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

