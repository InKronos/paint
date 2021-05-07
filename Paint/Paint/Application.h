#pragma once
#include "stdafx.h"
#include "Pen.h"
#include "Interface.h"
#include "Mouse.h"
#include "Block.h"
#include "Block.cpp"
#include "Rectangle.h"
#include "Line.h"
#include "Circle.h"
#include "Brush.h"
#include "DrawableObject.h"


class Pen;
class SceneObject;


class Application
{
private:
	sf::RenderWindow window;
	Mouse mouse;
public:
	Application(const int& windowWidth = 800, const int& windowHeight = 400, const sf::String& windowName = "Paint");
	~Application();
	void run();
	bool isLeftButtonPressed;
	bool isShiftPressed;
	bool toDraw;
	bool ColorChanged;
	bool outLineIsSet;
	bool RectDrawed;
	sf::Vector2f lastPosition;
	std::vector<BaseBlock*> allBlockObject = {};

	std::vector<DrawableObject*> allDrawableObjects = {};
	//List list;
private:
	void events();
	void CreateInterface(sf::RenderWindow& window);
	void updateAll(sf::RenderWindow& window);
	void drawAll(sf::RenderWindow& window);
};

