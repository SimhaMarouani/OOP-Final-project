#include "playersInclude/Light.h"

Light::Light()
	:Players(Player::Light)
{
}
//
//Light::Light(sf::Vector2f position/*, Board& board*/)
//	:Players(Player::Light)
//{
//}
Light::Light(b2World* world)
	: Players(Player::Light, world)
{
	b2MassData mass;
	mass.center = m_body->GetLocalCenter();
	mass.mass = 3;
	m_body->SetMassData(&mass);
}
