#include "Settings.h"
#include "Controller.h"


Settings::Settings() //TODO: send current status
	: m_background(sf::Vector2f(SETTINGS_WIDTH, SETTINGS_HEIGHT)),
	m_shadow(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT)),
	m_exitSettingsBtn(*Resources::instance().getSettingsReturnTexture(ScreenType::HomePage)),
	m_redirectBtn(*Resources::instance().getSettingsHomeTexture()),
	m_btnsAudio(Resources::instance().getAudioClick()),
	m_currScreen(ScreenType::HomePage)

{
	m_shadow.setFillColor(sf::Color(255, 255, 255, 50));
	m_background.setTexture(Resources::instance().getSettingsBackground());
	m_background.setPosition(sf::Vector2f((WINDOW_WIDTH - SETTINGS_WIDTH) / 2, (WINDOW_HEIGHT - SETTINGS_HEIGHT) / 2));
	createBtns();
}

void Settings::draw(sf::RenderWindow& window, enum ScreenType s)
{
	window.draw(m_shadow);
	window.draw(m_background);

	for (auto& i : m_soundBtns)
	{
		i.draw(window);
	}

	m_exitSettingsBtn.draw(window);

	if(s == ScreenType::Game)
		m_redirectBtn.draw(window);
}

void Settings::update(enum ScreenType s)
{
	if (m_currScreen != s)
	{
		m_currScreen = s;
		m_exitSettingsBtn.setTexture(Resources::instance().getSettingsReturnTexture(s));
	}	
}

void Settings::handleClick(const sf::Event &event, enum ScreenType s)
{
	if (m_soundBtns[(int)Type::Audio].isContain(event))
	{
		SoundStatus type = Resources::instance().isAudioOn() ? SoundStatus::AudioOff : SoundStatus::AudioOn;
		m_soundBtns[(int)Type::Audio].setTexture(Resources::instance().getSoundTexture(type));
		Resources::instance().switchAudioStatus();
	}
	else if (m_soundBtns[(int)Type::Music].isContain(event))
	{
		SoundStatus type = Resources::instance().isMusicOn() ? SoundStatus::MusicOff : SoundStatus::MusicOn;
		m_soundBtns[(int)Type::Music].setTexture(Resources::instance().getSoundTexture(type));
		Resources::instance().switchMusicStatus(s);
	}
}

bool Settings::isContainExit(const sf::Event& e) const
{
	return m_exitSettingsBtn.isContain(e);
}

bool Settings::isContainHome(const sf::Event& e) const
{
	return m_redirectBtn.isContain(e);
}

void Settings::createBtns()
{
	initSoundButton();
	initTextButton();
}

void Settings::initSoundButton()
{
	auto startPos = m_background.getPosition();
	int i = (int)Type::Audio;
	int j = (int)Type::Music;

	m_soundBtns.resize(2);
	m_soundBtns[i].setTexture(Resources::instance().getSoundTexture(SoundStatus::AudioOn));
	m_soundBtns[i].setSize(sf::Vector2f(PLAYER_FACE_SIZE, PLAYER_FACE_SIZE));
	m_soundBtns[i].setPosition(startPos + sf::Vector2f((SETTINGS_WIDTH / 2) - (m_soundBtns[i].getSize().x), SETTINGS_HEIGHT / 6));

	m_soundBtns[j].setTexture(Resources::instance().getSoundTexture(SoundStatus::MusicOn));
	m_soundBtns[j].setSize(sf::Vector2f(PLAYER_FACE_SIZE, PLAYER_FACE_SIZE));
	m_soundBtns[j].setPosition(startPos + sf::Vector2f((SETTINGS_WIDTH / 2) - (m_soundBtns[j].getSize().x - PLAYER_FACE_SIZE), SETTINGS_HEIGHT / 6));
}

void Settings::initTextButton()
{
	//return
	m_exitSettingsBtn.setScale(sf::Vector2f(0.70f, 0.70f));
	m_exitSettingsBtn.setPosition(m_background.getPosition() + sf::Vector2f((SETTINGS_WIDTH / 2) - (m_exitSettingsBtn.getSize().x / 2), SETTINGS_HEIGHT * 4 /6));
	//home
	m_redirectBtn.setScale(sf::Vector2f(0.70f, 0.70f));
	m_redirectBtn.setPosition(m_background.getPosition() + sf::Vector2f((SETTINGS_WIDTH / 2) - (m_redirectBtn.getSize().x / 2), SETTINGS_HEIGHT * 3 / 6));
}


void Settings::handleHover(const sf::Vector2f& location)
{
    for (int i = 0; i < m_soundBtns.size(); ++i)
    {
		if (m_soundBtns[i].isHover(location))
		{

			m_soundBtns[i].setColor(sf::Color::Black);
            m_soundBtns[i].setSize(sf::Vector2f(PLAYER_FACE_SIZE + 1, PLAYER_FACE_SIZE + 1));
		}
		else
		{

			m_soundBtns[i].setColor(sf::Color::White);
            m_soundBtns[i].setSize(sf::Vector2f(PLAYER_FACE_SIZE, PLAYER_FACE_SIZE));
		}
    }

    if (m_exitSettingsBtn.isHover(location))
    {
		m_exitSettingsBtn.setColor(sf::Color::Black);
    }
    else if (m_redirectBtn.isHover(location))
    {
		m_redirectBtn.setColor(sf::Color::Black);
    }
    else
    {
		m_exitSettingsBtn.setColor(sf::Color::White);
		m_redirectBtn.setColor(sf::Color::White);
    }
}