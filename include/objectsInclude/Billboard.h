#pragma once
#include "StaticObjects.h"


class Billboard : public StaticObjects
{
public:
	Billboard(sf::Vector2f pos, b2World* world, sf::Vector2f scale);
private:

};