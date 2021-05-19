#include "Application.h"



Application::Application(const int& windowWidth, const int& windowHeight, const std::string& filename)
	:  lastPosition({0, 0})
{
	this->filename = filename;

	this->window.create(sf::VideoMode(windowWidth, windowHeight), sf::String("Paint: your file name is " + filename + ".png*"));
	this->window.setMouseCursorVisible(false);
	isLeftButtonPressed = false;
	toDraw = false;
	ColorChanged = false;
	outLineIsSet = false;
	isShiftPressed = false;
	isControlPressed = false;
	isZPressed = false;
	isYPressed = false;
	isSceneChanged = false;
	isSPressed = false;
	createEverything();
}

Application::~Application()
{
	for (auto objects : allDrawableObjects) {
		delete objects;
	}
	for (auto objects : allObjectsInClipboard) {
		delete objects;
	}
	for (auto objects : allBlockObject) {
		delete objects;
	}
	allTextures.clear();
	std::cout << "You just deleted the window!" << std::endl;
}

void Application::run()
{
    while (window.isOpen())
    {
		events();
		updateAll(window);
        window.clear();
		drawAll(window);
		window.draw(thicknessText);
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
				isShiftPressed = true;
			}
			if (event.key.code == sf::Keyboard::LControl) {
				isControlPressed = true;
			}
			if (event.key.code == sf::Keyboard::Z) {
				isZPressed = true;
			}
			if (event.key.code == sf::Keyboard::Y) {
				isYPressed = true;
			}
			if (event.key.code == sf::Keyboard::S) {
				isSPressed = true;
			}
		}

		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::LShift) {
				isShiftPressed = false;
			}
			if (event.key.code == sf::Keyboard::LControl) {
				isControlPressed = false;
			}
			if (event.key.code == sf::Keyboard::Z) {
				isZPressed = false;
			}
			if (event.key.code == sf::Keyboard::Y) {
				isYPressed = false;
			}
			if (event.key.code == sf::Keyboard::S) {
				isSPressed = false;
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
			}
		}

	}
}


void Application::updateAll(sf::RenderWindow& window)
{
	mouse.update(window);
	updateClipboard();
	saveFile();
	drawFunction();
	isBlockClicedFunction();
}

void Application::drawAll(sf::RenderWindow& window)
{
	for (auto i = 0; i < allDrawableObjects.size(); i++)
	{
		allDrawableObjects[i]->draw(window);
	}
	
	for (auto i = 0; i < allBlockObject.size(); i++)
	{
		allBlockObject[i]->draw(window);
	}
	mouse.draw(window);
	
	
}

void Application::updateClipboard()
{
	if (!isSceneChanged) {
		if (isControlPressed && isYPressed) {
			if (allObjectsInClipboard.size() == 0)
				return;
			allDrawableObjects.push_back(allObjectsInClipboard.back());
			allObjectsInClipboard.pop_back();
			isSceneChanged = true;
		}
		if (isControlPressed && isZPressed) {
			if (allDrawableObjects.size() == 0)
				return;
			allObjectsInClipboard.push_back(allDrawableObjects.back());
			allDrawableObjects.pop_back();
			isSceneChanged = true;
		}
	}
	else {
		if (!isControlPressed)
			isSceneChanged = false;
		if (!isZPressed && !isYPressed)
			isSceneChanged = false;
	}
		
}

void Application::clearClipboard()
{
	for (auto objects : allObjectsInClipboard) {
		delete objects;
	}
	allObjectsInClipboard.clear();
}


void Application::saveFile()
{
	if (!toDraw) {
		if ((isSPressed && isControlPressed) || doSave) {
			sf::Texture texture;
			sf::Vector2f GrayBlockSize = allBlockObject[0]->getSize();
			texture.create(window.getSize().x, window.getSize().y);
			texture.update(window);
			sf::Image image2 = texture.copyToImage();
			sf::Image image;
			image.create(window.getSize().x, window.getSize().y - (window.getSize().y/8));
			image.copy(image2, 0, 0, sf::IntRect(0, (window.getSize().y / 8), window.getSize().x, window.getSize().y));
			image.saveToFile(std::string(this->filename + ".png"));
			doSave = false;
			toDraw = true;
			window.setTitle(sf::String("Paint: your file name is " + filename + ".png"));
		}
	}
}

void Application::createEverything()
{
	if (!font.loadFromFile("arial.ttf"))
		std::cout << "ERROR" << std::endl;
	thicknessText.setFont(font);
	thicknessText.setString(std::to_string(mouse.getThickness()));
	thicknessText.setCharacterSize(24);
	thicknessText.setFillColor(sf::Color::Black);
	thicknessText.setStyle(sf::Text::Bold);
	thicknessText.setPosition(sf::Vector2f({ 287, 10 }));
	allTextures = std::vector<sf::Texture>(10);
	allTextures[0].loadFromFile("Images/rect.png");
	allTextures[1].loadFromFile("Images/circle.png");
	allTextures[2].loadFromFile("Images/line.png");
	allTextures[3].loadFromFile("Images/pencil.png");
	allTextures[4].loadFromFile("Images/brush.png");
	allTextures[5].loadFromFile("Images/fillInside.png");
	allTextures[6].loadFromFile("Images/LArrow.png");
	allTextures[7].loadFromFile("Images/RArrow.png");
	allTextures[8].loadFromFile("Images/clear.png");
	allTextures[9].loadFromFile("Images/save.png");
	allBlockObject.push_back(new Block<std::string>(sf::Vector2f({ 0, 0 }), sf::Vector2f({ 800, 50 }), sf::Color::Color(100, 100, 100), "Interface gray block to check if mouse is clicek on it"));
	allBlockObject.push_back(new Block<sf::Color>(sf::Vector2f({ 640, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Yellow, sf::Color::Yellow));
	allBlockObject.push_back(new Block<sf::Color>(sf::Vector2f({ 680, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Blue, sf::Color::Blue));
	allBlockObject.back()->setOutLineColor();
	allBlockObject.push_back(new Block<sf::Color>(sf::Vector2f({ 720, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Green, sf::Color::Green));
	allBlockObject.push_back(new Block<sf::Color>(sf::Vector2f({ 760, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Red, sf::Color::Red));
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 20, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::White, drawType::Pen));
	allBlockObject.back()->setTexture(allTextures[3]);
	allBlockObject.back()->setOutLineColor();
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 60, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::White, drawType::Rectangle));
	allBlockObject.back()->setTexture(allTextures[0]);
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 100, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::White, drawType::Line));
	allBlockObject.back()->setTexture(allTextures[2]);
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 140, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::White, drawType::Circle));
	allBlockObject.back()->setTexture(allTextures[1]);
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 180, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::White, drawType::Brush));
	allBlockObject.back()->setTexture(allTextures[4]);

	allBlockObject.push_back(new Block<int>(sf::Vector2f({ 262, 10 }), sf::Vector2f({ 8, 30 }), sf::Color::Color(50, 50, 50), -1));
	allBlockObject.back()->setTexture(allTextures[6]);
	allBlockObject.push_back(new Block<int>(sf::Vector2f({ 316, 10 }), sf::Vector2f({ 8, 30 }), sf::Color::Color(50, 50, 50), 1));
	allBlockObject.back()->setTexture(allTextures[7]);
	allBlockObject.push_back(new Block<std::string>(sf::Vector2f({ 278, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Color(50, 50, 50), "BackGround Block for thickness number"));
	allBlockObject.push_back(new Block<std::pair<std::string, bool>>(sf::Vector2f({ 340, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::White, std::make_pair<std::string, bool>("Fill", false)));
	allBlockObject.back()->setTexture(allTextures[5]);
	allBlockObject.push_back(new Block<std::pair<std::string, bool>>(sf::Vector2f({ 380, 10 }), sf::Vector2f({ 60, 30 }), sf::Color::Color(72, 150, 84), std::make_pair<std::string, bool>("Clear", false)));
	allBlockObject.back()->setTexture(allTextures[8]);
	allBlockObject.push_back(new Block<std::pair<std::string, bool>>(sf::Vector2f({ 450, 10 }), sf::Vector2f({ 60, 30 }), sf::Color::Color(72, 150, 84), std::make_pair<std::string, bool>("Save", false)));
	allBlockObject.back()->setTexture(allTextures[9]);
}

void Application::drawFunction()
{
	if (!toDraw && isLeftButtonPressed && !allBlockObject[0]->isClicked(mouse.getPosition())) {
		toDraw = true;
		clearClipboard();
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
		window.setTitle(sf::String("Paint: your file name is " + filename + ".png*"));
	}
	if (toDraw) {

		if (isShiftPressed && (typeid(*allDrawableObjects.back()) != typeid(Rectangle) || typeid(*allDrawableObjects.back()) != typeid(Circle))) {
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

void Application::isBlockClicedFunction()
{
	
	if (!toDraw && isLeftButtonPressed) {
		for (auto i = 1; i < allBlockObject.size(); i++)
		{
			if (allBlockObject[i]->isClicked(mouse.getPosition()) && !ColorChanged) {
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
					thicknessText.setString(std::to_string(mouse.getThickness()));
					if (mouse.getThickness() < 10)
						thicknessText.setPosition(sf::Vector2f({ 287, 10 }));
					else
						thicknessText.setPosition(sf::Vector2f({ 278, 10 }));
					if (mouse.getThickness() == 2 || mouse.getThickness() == 15)
						thicknessText.setFillColor(sf::Color::Red);
					else
						thicknessText.setFillColor(sf::Color::Black);
					ColorChanged = true;
					break;
				}
				else if (typeid(*allBlockObject[i]) == typeid(Block<std::pair<std::string, bool>>)) {
					Block<std::pair<std::string, bool>>* clicedBlock = (Block<std::pair<std::string, bool>>*) allBlockObject[i];
					std::pair<std::string, bool> atribiutes = clicedBlock->getUniqueAttribute();
					if (atribiutes.first == "Fill") {
						if (atribiutes.second == true) {
							clicedBlock->deleteOutLineColor();
							atribiutes.second = false;
							clicedBlock->setUniqueAttribute(atribiutes);
						}
						else {
							clicedBlock->setOutLineColor();
							atribiutes.second = true;
							clicedBlock->setUniqueAttribute(atribiutes);
						}
						mouse.setAddFillColor(atribiutes.second);
						ColorChanged = true;
						std::cout << "WYPELNIENIE ZMIENIONE " << std::endl;
					}
					else if (atribiutes.first == "Clear") {
						ColorChanged = true;
						for (auto objects : allDrawableObjects) {
							delete objects;
						}
						allDrawableObjects.clear();
					}
					else if (atribiutes.first == "Save") {
						ColorChanged = true;
						doSave = true;
					}
					break;
				}
			}
			if (ColorChanged && outLineIsSet) {
				for (auto j = 1; j < allBlockObject.size(); j++) {
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
}


