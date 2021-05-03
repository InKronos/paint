#pragma once
#include "SceneObject.h"
class BaseBlock :
    public SceneObject
{
protected:
	sf::RectangleShape shape;
	sf::Vector2f position;
	sf::Vector2f size;
public:
	BaseBlock(sf::Vector2f position, sf::Vector2f size, sf::Color color);
	~BaseBlock();
	bool isClicked(sf::Vector2f mousePosition);
	void setOutLineColor();
	void deleteOutLineColor();
	void draw(sf::RenderWindow& window);
};

