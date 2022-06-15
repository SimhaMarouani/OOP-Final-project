#include "playersInclude/Light.h"


Light::Light(b2World* world)
	: Players(Player::Light, sf::Vector2u(5, 8), world)
{
	b2MassData mass;
	mass.center = m_body->GetLocalCenter();
	mass.mass = 15;
	mass.I = m_icon.getOrigin().y;
	m_body->SetMassData(&mass);
}

std::pair<int, int> Light::getAnimationData()
{
	Direction dir = Players::getCurrDirection();
	return std::pair<int, int>(lightAnimationRow[static_cast<int>(dir)]);
}

int Light::getJumpImpulse()
{
	return m_body->GetMass() * (-31);
}
