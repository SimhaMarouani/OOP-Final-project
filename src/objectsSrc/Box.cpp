#include "objectsInclude/Box.h"

//Box::Box(b2World* world)
//	:StaticObjects(Objects::Hay, world, sf::Vector2f(0, 600))
//{
//}

Box::Box(sf::Vector2f pos, b2World* world, sf::Vector2f scale)
	: StaticObjects(Objects::Hay, world, pos, scale)
{
	//setPosition(pos);
	b2MassData mass;
	mass.center = m_body->GetLocalCenter();
	mass.mass = 1;
	m_body->SetMassData(&mass);
}
