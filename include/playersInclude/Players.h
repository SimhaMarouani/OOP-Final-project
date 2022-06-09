#pragma once
#include "GameObjects.h"

class Players : public GameObjects
{
public:
	Players(Player type, b2World* world);


	void setDirection(Direction dir);
	void update();
	void move(float deltaTime);
	void setTouchingFloor(bool touching);
protected: //Tali: why protected? need change all protected members in other classes as well
	
	float m_speedPerSecond = BASE_SPEED;

	bool m_jumping = false;
	bool m_touchingFloor;
	Direction m_direction = Direction::None;
	b2Vec2 getDirection(Direction dir);


};