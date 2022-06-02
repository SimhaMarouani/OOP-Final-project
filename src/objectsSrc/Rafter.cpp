#include "objectsInclude/Rafter.h"

Rafter::Rafter()
	:StaticObjects(Objects::Rafter)
{
}

Rafter::Rafter(sf::Vector2f pos)
	: StaticObjects(Objects::Rafter)
{
	setPostition(pos);
}
