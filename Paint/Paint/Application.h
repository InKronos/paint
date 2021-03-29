#pragma once
#include "stdafx.h"

class Pen;

class Application
{
private:
	sf::RenderWindow window;
public:
	Application();
	Application(const int& windowWidth = 800, const int& windowHeight = 400, const sf::String& windowName = "Paint");
	~Application();
	void run();
	bool isLeftButtonPressed;
	std::vector<Pen> allPenObjects = {};
	//List list;
private:
	void events();
	void CreateInterface(sf::RenderWindow& window);
	void updateAll(sf::RenderWindow& window);
	void drawAll(sf::RenderWindow& window);
};

