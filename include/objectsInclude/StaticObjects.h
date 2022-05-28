#pragma once
#include "GameObjects.h"



class StaticObjects : public GameObjects
{
public:
	StaticObjects();
	StaticObjects(Objects type);

	void setPostition(sf::Vector2f pos);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape m_shape;
	sf::Sprite m_icon;
};