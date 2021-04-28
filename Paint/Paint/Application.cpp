#include "Application.h"

Interface interfaceObject;

Application::Application(const int& windowWidth, const int& windowHeight, const sf::String& windowName)
	:window(sf::VideoMode(windowWidth, windowHeight), windowName), isLeftButtonPressed(false), lastPosition({0, 0}), toDraw(false)
{
}

Application::~Application()
{
	std::cout << "You just deleted the window!" << std::endl;
}

void Application::run()
{
	//List list;
	sf::VertexArray cirles(sf::TriangleStrip, 4);
	
	
    while (window.isOpen())
    {
		events();
		updateAll(window);
        window.clear();
		drawAll(window);
		window.draw(cirles);
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
	if (isLeftButtonPressed && lastPosition != actualPosition) {
		//std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
		Pen penBlock(sf::Vector2f(mousePosition.x, mousePosition.y), lastPosition, toDraw);
		allPenObjects.push_back(penBlock);
		lastPosition = actualPosition;
		toDraw = true;
	}
}

void Application::drawAll(sf::RenderWindow& window)
{
	interfaceObject.draw(window);
	for (auto i = 0; i < allPenObjects.size(); i++)
	{
		allPenObjects[i].draw(window);
	}
}
