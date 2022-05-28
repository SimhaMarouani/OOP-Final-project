#include "objectsInclude/StaticObjects.h"

StaticObjects::StaticObjects()
{
}

StaticObjects::StaticObjects(Objects type)
{
	m_icon.setTexture(*Resources::instance().getObjectTexture(type));
	m_icon.setScale(sf::Vector2f(0.6, 0.6));
	m_icon.setOrigin(m_icon.getGlobalBounds().width, m_icon.getGlobalBounds().height);
}

void StaticObjects::setPostition(sf::Vector2f pos)
{
	//m_shape.setPosition(pos);
	m_icon.setPosition(pos);

}

void StaticObjects::draw(sf::RenderWindow & window)
{
	//window.draw(m_shape);  //remove
	window.draw(m_icon);
}