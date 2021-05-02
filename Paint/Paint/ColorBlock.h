#pragma once
#include "stdafx.h"
#include "Block.h"
class ColorBlock :
    public Block
{
public:
    ColorBlock(sf::Vector2f position, sf::Vector2f size, sf::Color color);
    ~ColorBlock();
    sf::Color getColor();
};

