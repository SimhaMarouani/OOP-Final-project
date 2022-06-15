#include "objectsInclude/Door.h"

Door::Door(sf::Vector2f pos, Grounds type, b2World* world, sf::Vector2f scale)
	: StaticObjects(type, world, pos, scale), m_open(false), m_moved(true), m_audio(Resources::instance().getDoorSound())
{
}

void Door::setOpen(bool open)
{
	if(m_open != open)
		m_moved = false;

	m_open = open;
}

void Door::updateDoorState()
{
	if (m_open && !m_moved)
	{
		m_audio.playAudio(20);
		setPosition(sf::Vector2f(m_body->GetPosition().x, m_body->GetPosition().y - DOOR_OFFSET));
		m_moved = true;
	}
	else if (!m_open && !m_moved)
	{
		m_audio.playAudio(20);
		setPosition(sf::Vector2f(m_body->GetPosition().x, m_body->GetPosition().y + DOOR_OFFSET));
		m_moved = true;	
	}
}