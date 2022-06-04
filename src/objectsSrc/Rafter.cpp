#include "objectsInclude/Rafter.h"

Rafter::Rafter(b2World* world)
	:StaticObjects(Objects::Rafter, world, sf::Vector2f(0, 600))
{
}

Rafter::Rafter(sf::Vector2f pos, b2World* world)
	: StaticObjects(Objects::Rafter, world, pos)
{
	//setPosition(pos);
	b2MassData mass;
	mass.center = m_body->GetLocalCenter();
	mass.mass = 1;
	m_body->SetMassData(&mass);
}
