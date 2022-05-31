#include "Button.h"

Button::Button(sf::Texture &texture, sf::Vector2f size)
	: m_button(texture)
{
	
	m_button.setScale(size.x / m_button.getTexture()->getSize().x, size.y / m_button.getTexture()->getSize().y); //Noga: when we use sprite - send size in px and calc the right scale
	//m_button.setTexture(&texture);
	//m_button.setScale(sf::Vector2f(1, 1));
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
	//m_button.setSize(size);
}

//void Button::setOutline(sf::Color color, float thickness)
//{
//	//m_button.setColor(sf::Color(sf::Color::White));
//	//m_button.setOutlineThickness(thickness);
//	//m_button.setOutlineColor(color);
//}

