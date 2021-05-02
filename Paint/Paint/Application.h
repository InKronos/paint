#pragma once
#include "stdafx.h"
#include "Pen.h"
#include "Interface.h"
#include "Mouse.h"
#include "ColorBlock.h"
#include "FuncionalBlock.h"
#include "Rectangle.h"
class Pen;
class ColorBlock;

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
	bool toDraw;
	bool ColorChanged;
	bool outLineIsSet;
	bool RectDrawed;
	sf::Vector2f lastPosition;
	std::vector<Pen> allPenObjects = {};
	std::vector<ColorBlock> allBlockObject = {};
	std::vector<FuncionalBlock> allFBlockObject = {};
	std::vector<Rectangle> allRectObjects = {};
	//List list;
private:
	void events();
	void CreateInterface(sf::RenderWindow& window);
	void updateAll(sf::RenderWindow& window);
	void drawAll(sf::RenderWindow& window);
};

