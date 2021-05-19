/**
 * @file class Block.h
 * @brief plik zawiekaj¹cy klase Block która dziedziczy od BaseBlock, jest specjan¹ szablonem bloków
 */
#pragma once
#include "stdafx.h"
#include "SceneObject.h"
#include "BaseBlock.h"


 /** Szablon obiektu klasy Block */
template <class T>
class Block : public BaseBlock
{
private:
	T uniqueAttribute; ///< unikalny atrybut
public:
	/** Konstruktor klasy Block
	 * @param position pozycja bloku
	 * @param size rozmiar bloku
	 * @param color kolor bloku
	 * @param uniqueAttribute_ unikalny atrybut bloku
	 */
	Block(sf::Vector2f position, sf::Vector2f size, sf::Color color, T uniqueAttribute_);

	/** Dekonstruktor klasy Block */
	~Block();
	
	/** Setter aktualizuje unikalny atrybut
	 * @param uniqueAttribute_ unikalny atrybut
	 */
	void setUniqueAttribute(T uniqueAttribute_);

	/** Getter który zwraca unikalny atrybut
	 * @return unikalny atrybut
	 */
	T getUniqueAttribute();
};

