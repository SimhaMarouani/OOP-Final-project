#pragma once
#include "GameObjects.h"


class StaticObjects : public GameObjects
{
public:
	StaticObjects();

	void setPostition(sf::Vector2f pos);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape m_shape;

};