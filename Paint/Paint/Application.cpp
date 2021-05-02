#include "Application.h"

Interface interfaceObject;

Application::Application(const int& windowWidth, const int& windowHeight, const sf::String& windowName)
	:window(sf::VideoMode(windowWidth, windowHeight), windowName), isLeftButtonPressed(false), lastPosition({0, 0}), toDraw(false), ColorChanged(false), outLineIsSet(false)
{
	this->RectDrawed = false;
}

Application::~Application()
{
	std::cout << "You just deleted the window!" << std::endl;
}

void Application::run()
{
	//List list;
	//PLAYGROUND
	//------------------------------------------------------------------------

	allBlockObject.push_back(ColorBlock(sf::Vector2f({ 200, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Yellow));
	allBlockObject.push_back(ColorBlock(sf::Vector2f({ 240, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Blue));
	allBlockObject[1].setOutLineColor();
	allBlockObject.push_back(ColorBlock(sf::Vector2f({ 280, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Green));
	allBlockObject.push_back(ColorBlock(sf::Vector2f({ 320, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Red));
	allFBlockObject.push_back(FuncionalBlock(sf::Vector2f({ 20, 10 }), sf::Vector2f({ 30, 30 }), drawType::Pen));
	allFBlockObject[0].setOutLineColor();
	allFBlockObject.push_back(FuncionalBlock(sf::Vector2f({ 60, 10 }), sf::Vector2f({ 30, 30 }), drawType::Rectangle));
	std::cout << "TYP ZMIENIONY " << static_cast<std::underlying_type<drawType>::type>(allFBlockObject[1].getDrawType()) << std::endl;

	//------------------------------------------------------------------------
    while (window.isOpen())
    {
		events();
		updateAll(window);
        window.clear();
		drawAll(window);
        window.display();
    }

}

void Application::events()
{
	sf::Event event;
	this->window.setFramerateLimit(240);
	while (this->window.pollEvent(event))
	{

		if (event.type == sf::Event::Closed)
		{
			this->window.close();
			std::cout << "You just closed the window!" << std::endl;
		}

		if (event.type == sf::Event::Resized)
		{
			std::cout << "New width is " << this->window.getSize().x << ", new height is " << this->window.getSize().y << std::endl;
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left) {
				std::cout << "Pressed" << std::endl;
				isLeftButtonPressed = true;
			}
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.key.code == sf::Mouse::Left) {
				isLeftButtonPressed = false;
				toDraw = false;
				ColorChanged = false;
				RectDrawed = false;
			}
		}
	}
}

void Application::CreateInterface(sf::RenderWindow& window)
{
	
}

void Application::updateAll(sf::RenderWindow& window)
{
	mouse.update(window);
	//sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	//sf::Vector2f actualPosition( mousePosition.x, mousePosition.y );
	for (auto i = 0; i < allBlockObject.size(); i++)
	{
		if (allBlockObject[i].isClicked(mouse.getPosition()) && !ColorChanged && isLeftButtonPressed) {
			mouse.setColor(allBlockObject[i].getColor());
			//allBlockObject[i].setOutLineColor();
			std::cout << "KOLOR ZMIENIONY" << std::endl;
			ColorChanged = true;
			outLineIsSet = true;
		}
		if (ColorChanged && outLineIsSet) {
			for (auto j = 0; j < allBlockObject.size(); j++) {
				if (j == i)
					allBlockObject[j].setOutLineColor();
				else
					allBlockObject[j].deleteOutLineColor();
			}
			outLineIsSet = false;
			break;
		}
		
	}
	for (auto i = 0; i < allFBlockObject.size(); i++)
	{
		if (allFBlockObject[i].isClicked(mouse.getPosition()) && !ColorChanged && isLeftButtonPressed) {
			mouse.setDrawType(allFBlockObject[i].getDrawType());
			std::cout << "TYP ZMIENIONY " << static_cast<std::underlying_type<drawType>::type>(allFBlockObject[i].getDrawType()) << std::endl;
			ColorChanged = true;
			outLineIsSet = true;
		}
		if (ColorChanged && outLineIsSet) {
			for (auto j = 0; j < allFBlockObject.size(); j++) {
				if (j == i)
					allFBlockObject[j].setOutLineColor();
				else
					allFBlockObject[j].deleteOutLineColor();
			}
			outLineIsSet = false;
			break;
		}

	}
	if (mouse.getDrawType() == drawType::Pen)
	{
		if (isLeftButtonPressed && lastPosition != mouse.getPosition() && !ColorChanged) {
			Pen penBlock(mouse.getPosition(), lastPosition, toDraw, mouse.getColor());
			allPenObjects.push_back(penBlock);
			lastPosition = mouse.getPosition();
			toDraw = true;
		}
	}
	if (mouse.getDrawType() == drawType::Rectangle) {
		if (!toDraw && isLeftButtonPressed) {
			toDraw = true;
			allRectObjects.push_back(Rectangle(mouse.getPosition(), mouse.getColor()));
		}
		if (toDraw) {
			allRectObjects[allRectObjects.size() - 1].update(mouse.getPosition());
		}
	}
	
}

void Application::drawAll(sf::RenderWindow& window)
{
	for (auto i = 0; i < allPenObjects.size(); i++)
	{
		allPenObjects[i].draw(window);
	}
	for (auto i = 0; i < allRectObjects.size(); i++)
	{
		allRectObjects[i].draw(window);
	}
	interfaceObject.draw(window);
	for (auto i = 0; i < allBlockObject.size(); i++)
	{
		allBlockObject[i].draw(window);
	}
	
	for (auto i = 0; i < allFBlockObject.size(); i++)
	{
		allFBlockObject[i].draw(window);
	}
	
	
	
}
