#include "TitledButton.h"


TitledButton::TitledButton(sf::Vector2f ButtonSize, std::string str, float textSize, sf::Vector2f textPos, sf::Font &font)
	: Button(ButtonSize)
{
	setTextAttributes(str, textSize, textPos, font);
}

void TitledButton::setTextString(std::string text)
{
	m_buttonText.setString(text);
}

void TitledButton::setTextColor(sf::Color c)
{
	m_buttonText.setColor(c);
}

void TitledButton::setTextSize(float s)
{
	m_buttonText.setCharacterSize(s);
}

void TitledButton::setTextPosition(sf::Vector2f p)
{
	m_buttonText.setPosition(p);
}

void TitledButton::setTextFont(sf::Font &f)
{
	m_buttonText.setFont(f);
}

void TitledButton::draw(sf::RenderWindow& window)
{
	Button::draw(window);
	window.draw(m_buttonText);
}

void TitledButton::setTextAttributes(std::string str, float textSize, sf::Vector2f textPos, sf::Font &font)
{
	setTextString(str);
	setTextFont(font);
	setTextPosition(textPos);
	setTextSize(textSize);
}
