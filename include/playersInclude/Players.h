#pragma once
#include "GameObjects.h"
#include "Macros.h"
#include "Utilities.h"

class Players : public GameObjects
{
public:
	Players();
	Players(Player type);

	void setPostition(sf::Vector2f pos);
	sf::Vector2f getDirection();
	void setDirection(Direction dir);

	void draw(sf::RenderWindow& window);
	void move(float deltaTime);

	//virtual void move(float deltaTime) = 0;
//	void move(Controller& controller) {};

private:
	sf::Sprite m_icon; //Tali: Move to GameObjects? then will have to make access functions

	//sf::Vector2f m_direction;

	float m_speedPerSecond = BASE_SPEED;

	Direction m_direction;

};