#pragma once
#include "SceneObject.h"
#include "stdafx.h"
#include <SFML/Graphics.hpp>


class SceneObject;

class Pen : public SceneObject
{
	sf::CircleShape rectPen;
	sf::VertexArray betweenCircle;
	
public:
	
	Pen(sf::Vector2f position, sf::Vector2f lastPostion, bool toDraw);
	~Pen();
	void draw(sf::RenderWindow& window);

};

