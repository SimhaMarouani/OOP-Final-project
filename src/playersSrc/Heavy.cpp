#include "playersInclude/Heavy.h"

Heavy::Heavy()
	:Players(Player::Heavy)
{
}
//
//Heavy::Heavy(sf::Vector2f position/*, Board& board*/)
//	:Players(Player::Heavy)
//{
//}

Heavy::Heavy(b2World* world)
	: Players(Player::Heavy, world)
{
	b2MassData mass;
	mass.center = m_body->GetLocalCenter();
	mass.mass = 8;
	m_body->SetMassData(&mass);
}
