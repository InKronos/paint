#include "Application.h"



Application::Application(const int& windowWidth, const int& windowHeight, const std::string& filename)
	: isLeftButtonPressed(false), lastPosition({0, 0}), toDraw(false), ColorChanged(false), outLineIsSet(false), isShiftPressed(false)
{
	this->filename = filename;

	this->window.create(sf::VideoMode(windowWidth, windowHeight), sf::String("Paint: your file name is " + filename + ".png*"));
	interfaceObject = Interface();
	isControlPressed = false;
	isZPressed = false;
	isYPressed = false;
	isSceneChanged = false;
	isSPressed = false;
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
	
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		std::cout << "ERROR" << std::endl;
	thicknessText.setFont(font); 
	thicknessText.setString(std::to_string(mouse.getThickness()));
	thicknessText.setCharacterSize(24);
	thicknessText.setFillColor(sf::Color::Black);
	thicknessText.setStyle(sf::Text::Bold);
	thicknessText.setPosition(sf::Vector2f({ 287, 10 }));
	sf::Texture Rect;
	sf::Texture Circle;
	sf::Texture Line;
	sf::Texture Pencil;
	sf::Texture Brush;
	sf::Texture Fill;
	sf::Texture RArrow;
	sf::Texture LArrow;
	sf::Texture Clear;
	sf::Texture Save;
	Rect.loadFromFile("Images/rect.png");
	Circle.loadFromFile("Images/circle.png");
	Line.loadFromFile("Images/line.png");
	Pencil.loadFromFile("Images/pencil.png");
	Brush.loadFromFile("Images/brush.png");
	Fill.loadFromFile("Images/fillInside.png");
	LArrow.loadFromFile("Images/LArrow.png");
	RArrow.loadFromFile("Images/RArrow.png");
	Clear.loadFromFile("Images/clear.png");
	Save.loadFromFile("Images/save.png");
	allBlockObject.push_back(new Block<sf::Color>(sf::Vector2f({ 640, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Yellow, sf::Color::Yellow));

	std::cout << typeid(Block<sf::Color>).name() << std::endl;
	allBlockObject.push_back(new Block<sf::Color>(sf::Vector2f({ 680, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Blue, sf::Color::Blue));
	allBlockObject[1]->setOutLineColor();
	allBlockObject.push_back(new Block<sf::Color>(sf::Vector2f({ 720, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Green, sf::Color::Green));
	allBlockObject.push_back(new Block<sf::Color>(sf::Vector2f({ 760, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Red, sf::Color::Red));
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 20, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::White, drawType::Pen));
	allBlockObject.back()->setTexture(Pencil);
	allBlockObject.back()->setOutLineColor();
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 60, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::White, drawType::Rectangle));
	allBlockObject.back()->setTexture(Rect);
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 100, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::White, drawType::Line));
	allBlockObject.back()->setTexture(Line);
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 140, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::White, drawType::Circle));
	allBlockObject.back()->setTexture(Circle);
	allBlockObject.push_back(new Block<drawType>(sf::Vector2f({ 180, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::White, drawType::Brush));
	allBlockObject.back()->setTexture(Brush);

	allBlockObject.push_back(new Block<int>(sf::Vector2f({ 262, 10 }), sf::Vector2f({ 8, 30 }), sf::Color::Color(50, 50, 50), -1));
	allBlockObject.back()->setTexture(LArrow);
	allBlockObject.push_back(new Block<int>(sf::Vector2f({ 316, 10 }), sf::Vector2f({ 8, 30 }), sf::Color::Color(50, 50, 50), 1));
	allBlockObject.back()->setTexture(RArrow);
	allBlockObject.push_back(new Block<std::string>(sf::Vector2f({ 278, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::Color(50, 50, 50), "BackGround Block for thickness number"));
	allBlockObject.push_back(new Block<std::pair<std::string, bool>>(sf::Vector2f({ 340, 10 }), sf::Vector2f({ 30, 30 }), sf::Color::White, std::make_pair<std::string, bool>("Fill", false)));
	allBlockObject.back()->setTexture(Fill);
	allBlockObject.push_back(new Block<std::pair<std::string, bool>>(sf::Vector2f({ 380, 10 }), sf::Vector2f({ 60, 30 }), sf::Color::Color(72, 150, 84), std::make_pair<std::string, bool>("Clear", false)));
	allBlockObject.back()->setTexture(Clear);
	allBlockObject.push_back(new Block<std::pair<std::string, bool>>(sf::Vector2f({ 450, 10 }), sf::Vector2f({ 60, 30 }), sf::Color::Color(72, 150, 84), std::make_pair<std::string, bool>("Save", false)));
	allBlockObject.back()->setTexture(Save);
	//------------------------------------------------------------------------
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

void Application::CreateInterface(sf::RenderWindow& window)
{
	
}

void Application::updateAll(sf::RenderWindow& window)
{
	mouse.update(window);
	updateClipboard();
	SaveFile();
	if (!toDraw && isLeftButtonPressed) {
		for (auto i = 0; i < allBlockObject.size(); i++)
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
						std::cout << "WYPELNIENIE ZMIENIONE " << std::endl;
					}
					else if (atribiutes.first == "Clear") {
						for (auto objects : allDrawableObjects){
							delete objects;
						}
						allDrawableObjects.clear();
					}
					else if (atribiutes.first == "Save") {
						doSave = true;
					}
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
	
	this->interfaceObject.draw(window);
	for (auto i = 0; i < allBlockObject.size(); i++)
	{
		allBlockObject[i]->draw(window);
	}
	
	
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
	allObjectsInClipboard.clear();
}

void Application::SaveFile()
{
	if (!toDraw) {
		if ((isSPressed && isControlPressed) || doSave) {
			sf::Texture texture;
			texture.create(window.getSize().x, window.getSize().y);
			texture.update(window);
			sf::Image image2 = texture.copyToImage();
			sf::Image image;
			image.create(800, 350);
			image.copy(image2, 0, 0, sf::IntRect(0, 50, 800, 400));
			image.saveToFile(std::string(this->filename + ".png"));
			doSave = false;
			window.setTitle(sf::String("Paint: your file name is " + filename + ".png"));
		}
	}
}
