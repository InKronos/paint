#pragma once
#include "stdafx.h"

class SceneObject
{
public:
	SceneObject();
	~SceneObject();

	//virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};

