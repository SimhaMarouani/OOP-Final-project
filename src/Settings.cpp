#include "Settings.h"


Settings::Settings() //TODO: send current status
	:m_background(sf::Vector2f(SETTINGS_WIDTH, SETTINGS_HEIGHT)),
	m_exitSettingsBtn(*Resources::instance().getSettingsReturnTexture()),
	m_redirectBtn(*Resources::instance().getSettingsHomeTexture()),
	m_audioStatus(true)

{
	m_background.setTexture(Resources::instance().getSettingsBackground());
	m_background.setPosition(sf::Vector2f((WINDOW_WIDTH - SETTINGS_WIDTH) / 2, (WINDOW_HEIGHT - SETTINGS_HEIGHT) / 2));
	createBtns();

	//return
	m_exitSettingsBtn.setPosition(m_background.getPosition() + sf::Vector2f((SETTINGS_WIDTH / 2) - (m_redirectBtn.getSize().x / 2), SETTINGS_HEIGHT * 3 / 4));
	//home
	m_redirectBtn.setPosition(m_background.getPosition() + sf::Vector2f((SETTINGS_WIDTH / 2) - (m_redirectBtn.getSize().x / 2), SETTINGS_HEIGHT * 2 / 4));
}

void Settings::draw(sf::RenderWindow& window, Screen s)
{
	window.draw(m_background);

	for (auto& i : m_soundBtns)
	{
		i.draw(window);
	}

	m_exitSettingsBtn.draw(window);

	if(s == Screen::Game)
		m_redirectBtn.draw(window);
}

bool Settings::isContain(sf::Event event) const
{
	return m_background.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
}

void Settings::handleClick(sf::Event event, Screen s)
{
	if (m_soundBtns[(int)Type::Audio].isContain(event))
	{
		SoundStatus type = m_audioStatus ? SoundStatus::AudioOff : SoundStatus::AudioOn;
		m_soundBtns[(int)Type::Audio].setTexture(Resources::instance().getSoundTexture(type));
		m_audioStatus != m_audioStatus;
	}
	else if (m_soundBtns[(int)Type::Music].isContain(event))
	{
		SoundStatus type = Resources::instance().isMusicOn() ? SoundStatus::MusicOff : SoundStatus::MusicOn;
		m_soundBtns[(int)Type::Music].setTexture(Resources::instance().getSoundTexture(type));
		Resources::instance().switchMusicStatus(s);
	}
}

void Settings::createBtns()
{
	auto x = m_background.getPosition();
	auto y = m_background.getPosition();

	m_soundBtns.resize(2);
	m_soundBtns[(int)Type::Audio].setTexture(Resources::instance().getSoundTexture(SoundStatus::AudioOn));
	m_soundBtns[(int)Type::Audio].setSize(sf::Vector2f(PLAYER_FACE_SIZE, PLAYER_FACE_SIZE));
	m_soundBtns[(int)Type::Audio].setPosition(m_background.getPosition() + sf::Vector2f((SETTINGS_WIDTH / 2) - (m_soundBtns[(int)Type::Audio].getSize().x / 2 ), SETTINGS_HEIGHT / 4));

	m_soundBtns[(int)Type::Music].setTexture(Resources::instance().getSoundTexture(SoundStatus::MusicOn));
	m_soundBtns[(int)Type::Music].setSize(sf::Vector2f(PLAYER_FACE_SIZE, PLAYER_FACE_SIZE));
	m_soundBtns[(int)Type::Music].setPosition(m_background.getPosition() + sf::Vector2f((SETTINGS_WIDTH / 2) - (m_soundBtns[(int)Type::Music].getSize().x / 2 - PLAYER_FACE_SIZE ), SETTINGS_HEIGHT / 4));
	//m_soundBtns[(int)Type::Music].setPosition(m_background.getPosition() + sf::Vector2f(120, 10));
}
