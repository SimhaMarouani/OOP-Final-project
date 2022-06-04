#pragma once
#include "StaticObjects.h"


class Floor : public StaticObjects
{
public:
	Floor(Grounds type, b2World* world);
	Floor(sf::Vector2f pos, Grounds type, b2World* world);

private:
	void setAsGround();
};

