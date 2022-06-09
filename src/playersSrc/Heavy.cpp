#include "playersInclude/Heavy.h"


Heavy::Heavy(b2World* world)
	: Players(Player::Heavy, world)
{
	b2MassData mass;
	mass.center = m_body->GetLocalCenter();
	mass.mass = 40;
	mass.I = m_icon.getOrigin().y;
	m_body->SetMassData(&mass);
	//m_body->ResetMassData();
}
