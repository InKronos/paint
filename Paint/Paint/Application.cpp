#include "Application.h"

Interface interfaceObject;

Application::Application(const int& windowWidth, const int& windowHeight, const sf::String& windowName)
	:window(sf::VideoMode(windowWidth, windowHeight), windowName), isLeftButtonPressed(false), lastPosition({0, 0}), toDraw(false), ColorChanged(false), outLineIsSet(false), isShiftPressed(false)
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

	
	allBlockObject.push_back(new Block<sf::Color>(sf::Vector2f({ 640, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Yellow, sf::Color::Yellow));
	std::cout << typeid(Block<sf::Color>).name() << std::endl;
	allBlockObject.push_back(new Block<sf::Color>(sf::Vector2f({ 680, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Blue, sf::Color::Blue));
	allBlockObject[1]->setOutLineColor();
	allBlockObject.push_back(new Block<sf::Color>(sf::Vector2f({ 720, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Green, sf::Color::Green));
	allBlockObject.push_back(new Block<sf::Color>(sf::Vector2f({ 760, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Red, sf::Color::Red));
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 20, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Black, drawType::Pen));
	allBlockObject[4]->setOutLineColor();
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 60, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::White, drawType::Rectangle));
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 100, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Color(200, 200, 200), drawType::Line));
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 140, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Magenta, drawType::Circle));
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 180, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Cyan, drawType::Brush));

	allBlockObject.push_back(new Block<int>(sf::Vector2f({ 300, 10 }), sf::Vector2f({ 8, 30 }), sf::Color::Color(50, 50, 50), -1));
	allBlockObject.push_back(new Block<int>(sf::Vector2f({ 316, 10 }), sf::Vector2f({ 8, 30 }), sf::Color::Color(50, 50, 50), 1));

	allBlockObject.push_back(new Block<bool>(sf::Vector2f({ 340, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Color(50, 200, 50), false));

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

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::LShift) {
				std::cout << "Pressed Shift" << std::endl;
				isShiftPressed = true;
			}
		}

		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::LShift) {
				isShiftPressed = false;
			}
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left) {
				std::cout << "Pressed Left Mouse" << std::endl;
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
	if (!toDraw) {
		for (auto i = 0; i < allBlockObject.size(); i++)
		{
			if (allBlockObject[i]->isClicked(mouse.getPosition()) && !ColorChanged && isLeftButtonPressed) {
				if (typeid(*allBlockObject[i]) == typeid(Block<sf::Color>)) {
					Block<sf::Color>* clicedBlock = (Block<sf::Color>*) allBlockObject[i];
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
				else if (typeid(*allBlockObject[i]) == typeid(Block<int>)) {
					Block<int>* clicedBlock = (Block<int>*) allBlockObject[i];
					mouse.changeThickness(clicedBlock->getUniqueAttribute());
					std::cout << "GROBOSC ZMIENIONA " << mouse.getThickness() << std::endl;
					break;
				}
				else if (typeid(*allBlockObject[i]) == typeid(Block<bool>)) {
					Block<bool>* clicedBlock = (Block<bool>*) allBlockObject[i];
					if (clicedBlock->getUniqueAttribute() == true) {
						clicedBlock->deleteOutLineColor();
						clicedBlock->setUniqueAttribute(false);	
					}
					else {
						clicedBlock->setOutLineColor();
						clicedBlock->setUniqueAttribute(true);
					}
					mouse.setAddFillColor(clicedBlock->getUniqueAttribute());
					std::cout << "WYPELNIENIE ZMIENIONE " << clicedBlock->getUniqueAttribute() << std::endl;
					break;
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
	}
	if (!toDraw && isLeftButtonPressed) {
		toDraw = true;
		if (mouse.getDrawType() == drawType::Pen)
			allDrawableObjects.push_back(new Pen(mouse.getPosition(), mouse.getColor()));
		if (mouse.getDrawType() == drawType::Brush)
			allDrawableObjects.push_back(new Brush(mouse.getPosition(), mouse.getColor(), mouse.getThickness()));
		if (mouse.getDrawType() == drawType::Rectangle) 
			allDrawableObjects.push_back(new Rectangle(mouse.getPosition(), mouse.getColor(), mouse.getThickness(), mouse.getAddFillColor()));
		if (mouse.getDrawType() == drawType::Line) 
			allDrawableObjects.push_back(new Line(mouse.getPosition(), mouse.getColor(), mouse.getThickness()));
		if (mouse.getDrawType() == drawType::Circle) 
			allDrawableObjects.push_back(new Circle(mouse.getPosition(), mouse.getColor(), mouse.getThickness(), mouse.getAddFillColor()));
	}
	if (toDraw) {
		
		if (isShiftPressed && (typeid(*allDrawableObjects.back()) != typeid(Rectangle) || typeid(*allDrawableObjects.back()) != typeid(Circle))){
			if (typeid(*allDrawableObjects.back()) != typeid(Rectangle)) {
				Rectangle* rectToUpdate = (Rectangle*)allDrawableObjects.back();
				rectToUpdate->updateWithShift(mouse.getPosition());
			}
			else if (typeid(*allDrawableObjects.back()) != typeid(Circle)) {
				Circle* circleToUpdate = (Circle*)allDrawableObjects.back();
				circleToUpdate->updateWithShift(mouse.getPosition());
			}
		}
		else
			allDrawableObjects.back()->update(mouse.getPosition());
	}
	
	
}

void Application::drawAll(sf::RenderWindow& window)
{
	for (auto i = 0; i < allDrawableObjects.size(); i++)
	{
		allDrawableObjects[i]->draw(window);
	}
	
	interfaceObject.draw(window);
	for (auto i = 0; i < allBlockObject.size(); i++)
	{
		allBlockObject[i]->draw(window);
	}
	
	
}
