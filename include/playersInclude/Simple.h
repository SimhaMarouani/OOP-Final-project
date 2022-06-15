#pragma once
#include "playersInclude/Players.h"

class Simple : public Players
{
public:
	Simple(b2World* world);
	std::pair<int, int> getAnimationData();
	int getJumpImpulse();

private:

};