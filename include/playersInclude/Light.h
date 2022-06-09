#pragma once
#include "Players.h"

class Light : public Players
{
public:
	Light(b2World* world);
	std::pair<int, int> getAnimationData() {
		
		Direction dir = Players::getCurrDirection();
		return std::pair<int, int>(lightAnimationRow[int(dir)]);
	};

private:

};