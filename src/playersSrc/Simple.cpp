#include "playersInclude/Simple.h"


Simple::Simple(b2World* world)
	: Players(Player::Simple, sf::Vector2u(5, 10), world)
{
	b2MassData mass;
	mass.center = m_body->GetLocalCenter();
	mass.mass = 35;
	mass.I = m_icon.getOrigin().y;
	m_body->SetMassData(&mass);
}

int Simple::getJumpImpulse()
{
	return m_body->GetMass() * (-24);
}
