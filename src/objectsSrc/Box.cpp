#include "objectsInclude/Box.h"

Box::Box()
	:StaticObjects(Objects::Hay)
{
}

Box::Box(sf::Vector2f pos)
	: StaticObjects(Objects::Hay)
{
	setPosition(pos);
}
