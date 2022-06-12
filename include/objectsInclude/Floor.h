#pragma once
#include "StaticObjects.h"


class Floor : public StaticObjects
{
public:
	Floor(sf::Vector2f pos, Grounds type, b2World* world, sf::Vector2f scale);

private:
	void setAsGround();
};

