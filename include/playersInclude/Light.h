#pragma once
#include "playersInclude/Players.h"

class Light : public Players
{
public:
	Light(b2World* world);
	std::pair<int, int> getAnimationData();
	int getJumpImpulse();
private:

};