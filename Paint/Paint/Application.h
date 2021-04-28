#pragma once
#include "stdafx.h"
#include "Pen.h"
#include "Interface.h"
#include "Mouse.h"
class Pen;

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
	sf::Vector2f lastPosition;
	std::vector<Pen> allPenObjects = {};
	//List list;
private:
	void events();
	void CreateInterface(sf::RenderWindow& window);
	void updateAll(sf::RenderWindow& window);
	void drawAll(sf::RenderWindow& window);
};

