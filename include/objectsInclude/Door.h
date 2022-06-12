#pragma once
#include "StaticObjects.h"


class Door : public StaticObjects
{
public:
	Door(sf::Vector2f pos, Grounds type, b2World* world, sf::Vector2f scale);

private:
};
