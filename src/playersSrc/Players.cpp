#include "playersInclude/Players.h"

Players::Players()
{}

Players::Players(Player type)
{
	m_icon.setTexture(*Resources::instance().getPlayerTexture(type));
	m_icon.setScale(sf::Vector2f(0.5, 0.5));
}

void Players::draw(sf::RenderWindow& window)
{
	window.draw(m_icon);
}

void Players::setPostition(sf::Vector2f pos)
{
	m_icon.setPosition(pos);
}

sf::Vector2f Players::getDirection()
{
    switch (m_direction)
    {
    case Direction::Left:
        return sf::Vector2f(-1, 0);
    case Direction::Right:
        return sf::Vector2f(1, 0);
    case Direction::Up:
        return sf::Vector2f(0, -1);
    default:
        return sf::Vector2f(0, 0);
    }
}

void Players::move(float deltaTime)
{
    m_icon.move(getDirection() * m_speedPerSecond * deltaTime);
}

void Players::setDirection(Direction dir)
{
    m_direction = dir;
}
