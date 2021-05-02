#pragma once

#include "stdafx.h"
#include "Mouse.h"
#include "Block.h"

class FuncionalBlock :
    public Block
{
    drawType dType;
public:
    FuncionalBlock(sf::Vector2f position, sf::Vector2f size, drawType _type);
    ~FuncionalBlock();
    drawType getDrawType();
};

