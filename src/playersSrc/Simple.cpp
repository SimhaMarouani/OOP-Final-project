#include "playersInclude/Simple.h"


Simple::Simple(b2World* world)
	: Players(Player::Simple, world)
{
	b2MassData mass;
	mass.center = m_body->GetLocalCenter();
	mass.mass = 45;
	mass.I = m_icon.getOrigin().y;
	m_body->SetMassData(&mass);
	//m_body->ResetMassData();
}
