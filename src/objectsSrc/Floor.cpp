#include "objectsInclude/Floor.h"

Floor::Floor(sf::Vector2f pos, Grounds type, b2World* world, sf::Vector2f scale)
	: StaticObjects(type, world, pos, scale)
{
}

