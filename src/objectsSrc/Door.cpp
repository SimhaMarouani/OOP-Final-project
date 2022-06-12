#include "objectsInclude/Door.h"


Door::Door(sf::Vector2f pos, Grounds type, b2World* world, sf::Vector2f scale)
	: StaticObjects(type, world, pos, scale), m_open(false), m_moved(true)
{
}

void Door::setOpen(bool open)
{
	std::cout << "setting door\n";
	if(m_open != open)
		m_moved = false;

	m_open = open;
	//if (open)
	//{
	//	//transform door up constant amount
	//	m_body->SetTransform(b2Vec2(m_body->GetPosition().x, m_body->GetPosition().y + 200), 0);
	//}
	//else
	//{
	//	//transform door down constant amount
	//	m_body->SetTransform(b2Vec2(m_body->GetPosition().x, m_body->GetPosition().y - 200), 0);

	//}
}

void Door::updateDoorState()
{
	if (m_open && !m_moved)
	{
		m_body->SetTransform(b2Vec2(m_body->GetPosition().x, m_body->GetPosition().y - 300), 0);
		m_moved = true;
	}
	else if (!m_open && !m_moved)
	{
		m_body->SetTransform(b2Vec2(m_body->GetPosition().x, m_body->GetPosition().y + 300), 0);
		m_moved = true;	
	}
}