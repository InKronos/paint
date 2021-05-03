#pragma once
#include "stdafx.h"
#include "SceneObject.h"
#include "BaseBlock.h"

template <class T>
class Block : public BaseBlock
{
private:
	T uniqueAttribute;
public:
	Block(sf::Vector2f position, sf::Vector2f size, sf::Color color, T uniqueAttribute_);
	~Block();
	void setUniqueAttribute(T uniqueAttribute_);
	T getUniqueAttribute();
};

