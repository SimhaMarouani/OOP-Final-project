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

void Players::setDirection(sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Key::Left:
        m_direction = sf::Vector2f(-1, 0);
        break;

    case sf::Keyboard::Key::Right:
        m_direction = sf::Vector2f(1, 0);
        break;

    case sf::Keyboard::Key::Up:
        m_direction = sf::Vector2f(0, -1);
        break;

    case sf::Keyboard::Key::Down:
        m_direction = sf::Vector2f(0, 1);
        break;

    default:
        m_direction = sf::Vector2f(0, 0);
        break;
    }
}
