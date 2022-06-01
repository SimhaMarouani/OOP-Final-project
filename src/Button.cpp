#include "Button.h"

Button::Button(sf::Texture &texture, sf::Vector2f size)
	: m_button(texture)
{
	m_button.setScale(size.x / m_button.getTexture()->getSize().x, size.y / m_button.getTexture()->getSize().y);
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_button);
}

bool Button::isContain(sf::Event event) const
{
	return m_button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
}

void Button::setPosition(sf::Vector2f pos)
{
	m_button.setPosition(pos);
}

void Button::setTexture(sf::Texture *texture)
{
	m_button.setTexture(*texture);
}

void Button::setColor(sf::Color color)
{
	m_button.setColor(color);
}

void Button::setSize(sf::Vector2f size)
{
	m_button.setScale(size.x / m_button.getTexture()->getSize().x, size.y / m_button.getTexture()->getSize().y);
}