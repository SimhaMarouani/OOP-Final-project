#pragma once
#include "GameObjects.h"


class Players : public GameObjects
{
public:
	Players(); //remove
	Players(Player type); //remove
	Players(Player type, b2World* world);


	void setDirection(Direction dir);

	//void draw(sf::RenderWindow& window);
	void move(float deltaTime);

protected: //Tali: why protected? need change all protected members in other classes as well
	
	float m_speedPerSecond = BASE_SPEED;

	Direction m_direction = Direction::None;
	b2Vec2 getDirection(Direction dir);

};