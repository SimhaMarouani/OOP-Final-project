#include "Screens/Screen.h"

Screen::Screen(const sf::Texture *t)
	: m_background(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT)),
	m_btnAudio(Resources::instance().getAudioClick())
{
	m_background.setTexture(t);
}

void Screen::draw(sf::RenderWindow& window)
{
	window.draw(m_background);
}

void Screen::playClickAudio()
{
	m_btnAudio.playAudio();
}
