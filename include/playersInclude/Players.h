#pragma once
#include "GameObjects.h"
//#include "Controller.h"


class Players : public GameObjects
{
public:
	Players();
	Players(Player type);

	void draw(sf::RenderWindow& window);

//	void move(Controller& controller) {};

private:
	sf::Sprite m_icon;
};