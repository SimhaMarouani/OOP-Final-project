#include "objectsInclude/Box.h"

Box::Box(sf::Vector2f pos, b2World* world, sf::Vector2f scale)
	: StaticObjects(Objects::Hay, world, pos, scale), m_audio(Resources::instance().getHaySound())
{
	b2MassData mass;
	mass.center = m_body->GetLocalCenter();
	mass.mass = 40;
	mass.I = m_icon.getOrigin().y;
	m_body->SetMassData(&mass);
	m_body->GetFixtureList()->SetRestitution(0);
}

void Box::playAudio()
{
	m_audio.playAudio();
}
