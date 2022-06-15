#include "playersInclude/Heavy.h"


Heavy::Heavy(b2World* world)
	: Players(Player::Heavy, sf::Vector2u(5, 5), world)
{
	b2MassData mass;
	mass.center = m_body->GetLocalCenter();
	mass.mass = 55;
	mass.I = m_icon.getOrigin().y;
	m_body->SetMassData(&mass);
}

std::pair<int, int> Heavy::getAnimationData()
{
	Direction dir = Players::getCurrDirection();
	return std::pair<int, int>(heavyAnimationRow[static_cast<int>(dir)]);
}

int Heavy::getJumpImpulse()
{
	return m_body->GetMass() * (-21);
}
