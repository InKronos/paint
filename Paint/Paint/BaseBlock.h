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
	void setTexture(sf::Texture &texture);
	bool isClicked(sf::Vector2f mousePosition);
	void setOutLineColor();
	void deleteOutLineColor();
	sf::Vector2f getSize();
	void draw(sf::RenderWindow& window);
};

