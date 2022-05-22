#include "playersInclude/Players.h"

Players::Players()
{}

Players::Players(Player type)
{
	m_icon.setTexture(*Resources::instance().getPlayerTexture(type));
	m_icon.setScale(sf::Vector2f(0.7, 0.7));
}

void Players::draw(sf::RenderWindow& window)
{
	window.draw(m_icon);
}

void Players::setPostition(sf::Vector2f pos)
{
	m_icon.setPosition(pos);
}
