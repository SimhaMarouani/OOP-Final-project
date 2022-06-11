#include "objectsInclude/Rafter.h"

Rafter::Rafter(sf::Vector2f pos, b2World* world, sf::Vector2f scale)
	: StaticObjects(Objects::Rafter, world, pos, scale)
{
	b2MassData mass;
	mass.center = m_body->GetLocalCenter();
	mass.mass = 15;
	//mass.I = m_icon.getOrigin().x;
	m_body->SetMassData(&mass);
}
