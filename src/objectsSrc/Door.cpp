#include "objectsInclude/Door.h"


Door::Door(sf::Vector2f pos, Grounds type, b2World* world, sf::Vector2f scale)
	: StaticObjects(type, world, pos, scale), m_open(false), m_moved(true)
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
		setPosition(sf::Vector2f(m_body->GetPosition().x, m_body->GetPosition().y - 300));
		m_moved = true;
	}
	else if (!m_open && !m_moved)
	{
		setPosition(sf::Vector2f(m_body->GetPosition().x, m_body->GetPosition().y + 300));
		m_moved = true;	
	}
}