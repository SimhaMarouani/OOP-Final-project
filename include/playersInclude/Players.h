#pragma once
#include "GameObjects.h"
#include "Animation.h"

class Players : public GameObjects
{
public:
	Players(Player type, sf::Vector2u imageCount, b2World* world);

	void setDirection(Direction dir);
	void update(float deltaTime);
	void move(float deltaTime);
	void setTouchingFloor(bool touching);
	Direction getDir(sf::Vector2f dir) ;
	Direction getCurrDirection()const { return m_direction; };
	virtual std::pair<int, int> getAnimationData() = 0;
	/*sf::IntRect getWidth()const;
	sf::IntRect getheight()const;*/
	virtual int getJumpImpulse() = 0;
	void setFaceRight(bool f);
protected: //Tali: why protected? need change all protected members in other classes as well
	
	float m_speedPerSecond = BASE_SPEED;

	bool m_touchingFloor;
	//Direction m_direction = Direction::None;
	//b2Vec2 getDirection(Direction dir);
private: 
	Direction m_direction;
	void updateAnimation(float deltaTime);

	Animation m_animation;
	bool m_isFaceRight;


};