#include "playersInclude/Light.h"


Light::Light(b2World* world)
	: Players(Player::Light, world)
{
	b2MassData mass;
	mass.center = m_body->GetLocalCenter();
	mass.mass = 12;
	mass.I = m_icon.getOrigin().y;
	m_body->SetMassData(&mass);
	//m_body->ResetMassData();

}
