#include "objectsInclude/StaticObjects.h"

StaticObjects::StaticObjects()
{
}

StaticObjects::StaticObjects(Objects type)
{
	m_icon.setTexture(*Resources::instance().getObjectTexture(type));
	m_icon.setScale(sf::Vector2f(0.4, 0.4));
	m_icon.setOrigin(m_icon.getGlobalBounds().width, m_icon.getGlobalBounds().height);
}

StaticObjects::StaticObjects(Grounds type)
{
	m_icon.setTexture(*Resources::instance().getGroundTexture(type));
	if(type == Grounds::Left_l1)
		m_icon.setScale(sf::Vector2f(0.95, 0.7));
	else
		m_icon.setScale(sf::Vector2f(0.1, 0.07));
	m_icon.setOrigin(m_icon.getGlobalBounds().width, m_icon.getGlobalBounds().height);
}

void StaticObjects::setPostition(sf::Vector2f pos)
{
	m_icon.setPosition(pos);
}

void StaticObjects::draw(sf::RenderWindow & window)
{
	window.draw(m_icon);
}