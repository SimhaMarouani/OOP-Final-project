#pragma once
#include "StaticObjects.h"


class Box : public StaticObjects
{
public:
	Box(sf::Vector2f pos, b2World* world, sf::Vector2f scale);
	//Box(b2World* world);

private:

};