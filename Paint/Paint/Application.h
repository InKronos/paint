#pragma once
#include "stdafx.h"
#include "Pen.h"
#include "Mouse.h"
#include "Block.h"
#include "Block.cpp"
#include "Rectangle.h"
#include "Line.h"
#include "Circle.h"
#include "Brush.h"
#include "DrawableObject.h"



class Application
{
private:
	sf::RenderWindow window;
	Mouse mouse;
public:
	Application(const int& windowWidth = 800, const int& windowHeight = 400, const std::string& filename = "Paint");
	~Application();
	void run();
	
	bool isLeftButtonPressed;
	bool isShiftPressed;
	bool isControlPressed;
	bool isZPressed; 
	bool isYPressed;
	bool isSceneChanged;
	bool isSPressed;
	bool toDraw;
	bool ColorChanged;
	bool outLineIsSet;
	bool doSave;
	std::string filename;
	sf::Text thicknessText;
	sf::Font font;
	sf::Vector2f lastPosition;
	std::vector<BaseBlock*> allBlockObject = {};
	std::vector<DrawableObject*> allDrawableObjects = {};
	std::vector< DrawableObject*> allObjectsInClipboard = {};
	std::vector<sf::Texture> allTextures;
	//List list;
private:
	
	void events();
	void updateAll(sf::RenderWindow& window);
	void drawAll(sf::RenderWindow& window);
	void updateClipboard();
	void clearClipboard();
	void saveFile();
	void createEverything();
	void drawFunction();
	void isBlockClicedFunction();
};

