#pragma once
#include "StaticObjects.h"


class Box : public StaticObjects
{
public:
	Box(b2World* world);
	Box(sf::Vector2f pos, b2World* world);

private:

};