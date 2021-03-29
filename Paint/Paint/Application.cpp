#include "Application.h"

Interface interfaceObject;

Application::Application(const int& windowWidth, const int& windowHeight, const sf::String& windowName)
	:window(sf::VideoMode(windowWidth, windowHeight), windowName), isLeftButtonPressed(false)
{
}

Application::~Application()
{
	std::cout << "You just deleted the window!" << std::endl;
}

void Application::run()
{
	//List list;

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
			}
		}
	}
}

void Application::CreateInterface(sf::RenderWindow& window)
{
	
}

void Application::updateAll(sf::RenderWindow& window)
{
	if (isLeftButtonPressed) {
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		//std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
		Pen penBlock(sf::Vector2f(mousePosition.x, mousePosition.y));
		allPenObjects.push_back(penBlock);
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
