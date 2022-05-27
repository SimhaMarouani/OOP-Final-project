#include "..\..\include\Screens\SettingsScreen.h"

SettingsScreen::SettingsScreen()
	: m_background(sf::Vector2f(SETTINGS_WIDTH, SETTINGS_HEIGHT))
{
	auto offset_x = (WINDOW_HEIGHT - SETTINGS_HEIGHT) /2;
	auto offset_y = (WINDOW_WIDTH - SETTINGS_WIDTH) / 2;
	m_background.setPosition(offset_y, offset_x);
	m_background.setFillColor(sf::Color(143, 155, 176, 250));
}

void SettingsScreen::draw(sf::RenderWindow& window)
{
	window.draw(m_background);
}

void SettingsScreen::processEvents(sf::Event event)
{
}

bool SettingsScreen::isContain(sf::Event event)
{
	return m_background.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
}
