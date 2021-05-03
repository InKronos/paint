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
	
	//SceneObject* blok1 = new Block<sf::Color>(sf::Vector2f({ 200, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Yellow, sf::Color::Yellow);
	allBlockObject.push_back(new Block<sf::Color>(sf::Vector2f({ 200, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Yellow, sf::Color::Yellow));
	std::cout << typeid(Block<sf::Color>).name() << std::endl;
	allBlockObject.push_back(new Block<sf::Color>(sf::Vector2f({ 240, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Blue, sf::Color::Blue));
	allBlockObject[1]->setOutLineColor();
	allBlockObject.push_back(new Block<sf::Color>(sf::Vector2f({ 280, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Green, sf::Color::Green));
	allBlockObject.push_back(new Block<sf::Color>(sf::Vector2f({ 320, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Red, sf::Color::Red));
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 20, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Black, drawType::Pen));
	allBlockObject[4]->setOutLineColor();
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 60, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::White, drawType::Rectangle));
	//allBlockObject.push_back(blok1);
	//std::cout << typeid(allBlockObject[0]).name() << std::endl;

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
	for (auto i = 0; i < allBlockObject.size(); i++)
	{
		if (allBlockObject[i]->isClicked(mouse.getPosition()) && !ColorChanged && isLeftButtonPressed) {
			if (typeid(*allBlockObject[i]) == typeid(Block<sf::Color>)) {
				Block<sf::Color> *clicedBlock = (Block<sf::Color>*) allBlockObject[i];
				mouse.setColor(clicedBlock->getUniqueAttribute());
				std::cout << "KOLOR ZMIENIONY" << std::endl;
				ColorChanged = true;
				outLineIsSet = true;
			}
			else if (typeid(*allBlockObject[i]) == typeid(Block<drawType>)) {
				Block<drawType>* clicedBlock = (Block<drawType>*) allBlockObject[i];
				mouse.setDrawType(clicedBlock->getUniqueAttribute());
				std::cout << "TYP ZMIENIONY" << std::endl;
				ColorChanged = true;
				outLineIsSet = true;
			}
		}
		if (ColorChanged && outLineIsSet) {
			for (auto j = 0; j < allBlockObject.size(); j++) {
				if (typeid(*allBlockObject[i]) == typeid(*allBlockObject[j])) {
					if (j == i)
						allBlockObject[j]->setOutLineColor();
					else
						allBlockObject[j]->deleteOutLineColor();
				}
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
		allBlockObject[i]->draw(window);
	}
	
	
}
