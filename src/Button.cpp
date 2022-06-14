#include "Button.h"

Button::Button(const sf::Texture& texture, float scale)
	: Button(texture)
{
	m_button.setScale(scale, scale);
}

Button::Button(const sf::Texture &texture, const sf::Vector2f &size)
	: Button(texture)
{
	m_button.setScale(size.x / m_button.getTexture()->getSize().x, size.y / m_button.getTexture()->getSize().y);
}

Button::Button(const sf::Texture& texture)
	: m_button(texture)
{
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_button);
}

bool Button::isContain(sf::Event event) const
{
	return m_button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
}

const sf::Vector2f &Button::getSize() const
{
	sf::Vector2f textureSize = sf::Vector2f(m_button.getTexture()->getSize());
	sf::Vector2f scale = m_button.getScale();
	return 	sf::Vector2f(textureSize.x * scale.x, textureSize.y * scale.y);
}

bool Button::isHover(sf::Vector2f l) const
{
	return m_button.getGlobalBounds().contains(l);
}

void Button::setPosition(const sf::Vector2f& pos)
{
	m_button.setPosition(pos);
}

void Button::setTexture(const sf::Texture *texture)
{
	m_button.setTexture(*texture);
}

void Button::setColor(const sf::Color& color)
{
	m_button.setColor(color);
}

void Button::setSize(const sf::Vector2f &size)
{
	m_button.setScale(size.x / m_button.getTexture()->getSize().x, size.y / m_button.getTexture()->getSize().y);
}

void Button::setScale(const sf::Vector2f& scale)
{
	m_button.setScale(scale);
}