#pragma once
#include "playersInclude/Players.h"


class Heavy : public Players
{
public:
	Heavy(b2World* world);
	std::pair<int, int> getAnimationData() {

		Direction dir = Players::getCurrDirection();
		return std::pair<int, int>(heavyAnimationRow[int(dir)]);
	};
	int getJumpImpulse();

private:
};
