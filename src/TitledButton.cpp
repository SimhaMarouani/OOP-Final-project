#include "TitledButton.h"


TitledButton::TitledButton(const sf::Texture& texture, const sf::Vector2f &ButtonSize,
						const std::string str, unsigned int textSize,const sf::Vector2f &textPos,const sf::Font &font)
	: Button(texture, ButtonSize)
{
	setTextAttributes(str, textSize, textPos, font);
}

void TitledButton::setTextString(const std::string &text)
{
	m_buttonText.setString(text);
}

void TitledButton::setTextColor(const sf::Color &c)
{
	m_buttonText.setFillColor(c);
}

void TitledButton::setTextSize(unsigned int s)
{
	m_buttonText.setCharacterSize(s);
}

void TitledButton::setTextPosition(const sf::Vector2f &p)
{
	m_buttonText.setPosition(p);
}

void TitledButton::setTextFont(const sf::Font &f)
{
	m_buttonText.setFont(f);
}

void TitledButton::draw(sf::RenderWindow& window)
{
	Button::draw(window);
	window.draw(m_buttonText);
}

void TitledButton::setTextAttributes(const std::string& str, unsigned int textSize, const sf::Vector2f &textPos, const sf::Font &font)
{
	setTextString(str);
	setTextFont(font);
	setTextPosition(textPos);
	setTextSize(textSize);
}
