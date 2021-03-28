#include "stdafx.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 400), "SFML works!");
    Interface interfaceObject;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        interfaceObject.draw(window);
        window.display();
    }

    return 0;
}