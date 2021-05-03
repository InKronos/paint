#include "Block.h"

template<class T>
Block<T>::Block(sf::Vector2f position, sf::Vector2f size, sf::Color color, T uniqueAttribute_) 
	: BaseBlock( position, size, color), uniqueAttribute(uniqueAttribute_)
{
	
}

template<class T>
Block<T>::~Block()
{
}


template<class T>
void Block<T>::setUniqueAttribute(T uniqueAttribute_)
{
	this->uniqueAttribute = uniqueAttribute_;
}

template<class T>
T Block<T>::getUniqueAttribute()
{
	return this->uniqueAttribute;
}
