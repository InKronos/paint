#include "Application.h"

Interface interfaceObject;

Application::Application(const int& windowWidth, const int& windowHeight, const sf::String& windowName)
	:window(sf::VideoMode(windowWidth, windowHeight), windowName), isLeftButtonPressed(false), lastPosition({0, 0}), toDraw(false), ColorChanged(false), outLineIsSet(false)
{
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
	allBlockObject.push_back(ColorBlock(sf::Vector2f({ 280, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Green));
	allBlockObject.push_back(ColorBlock(sf::Vector2f({ 320, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Red));

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
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f actualPosition( mousePosition.x, mousePosition.y );
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
	if (isLeftButtonPressed && lastPosition != actualPosition && !ColorChanged) {
		//std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
		Pen penBlock(sf::Vector2f(mousePosition.x, mousePosition.y), lastPosition, toDraw, mouse.getColor());
		allPenObjects.push_back(penBlock);
		lastPosition = actualPosition;
		toDraw = true;
	}
}

void Application::drawAll(sf::RenderWindow& window)
{
	for (auto i = 0; i < allPenObjects.size(); i++)
	{
		allPenObjects[i].draw(window);
	}
	interfaceObject.draw(window);
	for (auto i = 0; i < allBlockObject.size(); i++)
	{
		allBlockObject[i].draw(window);
	}
	
}
