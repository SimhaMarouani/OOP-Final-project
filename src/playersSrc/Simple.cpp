#include "playersInclude/Simple.h"

Simple::Simple()
	:Players(Player::Simple)
{
}
//
//Simple::Simple(sf::Vector2f position/*, Board& board*/)
//	:Players(Player::Simple)
//{}
Simple::Simple(b2World* world)
	: Players(Player::Simple, world)
{
	b2MassData mass;
	mass.center = m_body->GetLocalCenter();
	mass.mass = 5;
	m_body->SetMassData(&mass);
}
