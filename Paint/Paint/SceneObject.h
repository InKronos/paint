/**
 * @file SceneObject.h
 * @brief plik zawiekaj�cy klase bazow� SceneObject, klasa ta jest klas� wirtualn�
 */
#pragma once
#include "stdafx.h"

 /** Klasa wirtualnego obiektu SceneObject */
class SceneObject
{
public:
	/** wirtualna funkcja do rysowania w oknie
	 * @param window okno do rysowania
	 */
	virtual void draw(sf::RenderWindow& window) = 0;
};

