#pragma once
#include "Players.h"

class Simple : public Players
{
public:
	Simple(b2World* world);
	std::pair<int, int> getAnimationData() {

		Direction dir = Players::getCurrDirection();
		return std::pair<int, int>(simpleAnimationRow[int(dir)]);
	};
	//void update(float deltaTime)
	//{
	//	Players::update(deltaTime);
	//	updateAnimation(deltaTime);
	//};
	int getJumpImpulse();

private:

};