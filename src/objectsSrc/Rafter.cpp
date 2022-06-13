#include "objectsInclude/Rafter.h"

Rafter::Rafter(sf::Vector2f pos, b2World* world, sf::Vector2f scale)
	: StaticObjects(Objects::Rafter, world, pos, scale)
{
	getBody()->GetFixtureList()->SetSensor(false);
	b2MassData mass;
	mass.center = getBody()->GetLocalCenter();
	mass.mass = 1;
	mass.I = m_icon.getOrigin().y;
	//mass.I = 400;
	getBody()->SetMassData(&mass);

	
	m_body->SetLinearDamping(0.1f);
	m_body->SetAngularDamping(0.1f);
}
