#pragma once
#include "GameObjects.h"
//#include "Controller.h"


class Players : public GameObjects
{
public:
	Players();
	Players(Player type);

	void setPostition(sf::Vector2f pos);
	void setDirection(sf::Keyboard::Key key);

	void draw(sf::RenderWindow& window);
	//virtual void move(float deltaTime) = 0;

//	void move(Controller& controller) {};

private:
	sf::Sprite m_icon;

	sf::Vector2f m_direction;
};