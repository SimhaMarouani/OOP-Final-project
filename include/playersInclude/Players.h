#pragma once
#include "GameObjects.h"
#include "Animation.h"
#include "Audio.h"

const float DEFAULT_SCALE = 0.5;
const float DEFAULT_START_Y = 600;

class Players : public GameObjects
{
public:
	Players(Player type, sf::Vector2u imageCount, b2World* world);

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
	void setDirection(Direction dir);

private: 
	float m_speedPerSecond = BASE_SPEED;
	bool m_touchingFloor;
	//bool m_moveBack; //Tali:needed?
	Direction m_direction;
	void updateAnimation(float deltaTime);

	Animation m_animation;
	bool m_isFaceRight;

	Audio m_audio;


};