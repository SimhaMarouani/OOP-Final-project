#include "objectsInclude/Floor.h"

Floor::Floor(Grounds type)
	:StaticObjects(type)
{
}

Floor::Floor(sf::Vector2f pos, Grounds type)
	: StaticObjects(type)
{
	setPostition(pos);
}
