#include "playersInclude/Players.h"

Players::Players()
{}

Players::Players(Player type)
{
	m_icon.setTexture(*Resources::instance().getPlayerTexture(type));
	m_icon.setScale(sf::Vector2f(1, 1));
}

void Players::draw(sf::RenderWindow& window)
{
	window.draw(m_icon);
}
