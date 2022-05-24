#include "objectsInclude/StaticObjects.h"

StaticObjects::StaticObjects()
{
}

void StaticObjects::setPostition(sf::Vector2f pos)
{
	m_shape.setPosition(pos);
}

void StaticObjects::draw(sf::RenderWindow & window)
{
	window.draw(m_shape);
}