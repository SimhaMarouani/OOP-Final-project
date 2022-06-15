#pragma once
#include "playersInclude/Players.h"


class Heavy : public Players
{
public:
	Heavy(b2World* world);
	std::pair<int, int> getAnimationData();
	int getJumpImpulse();

private:
};
