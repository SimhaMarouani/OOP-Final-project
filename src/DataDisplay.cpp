#include "DataDisplay.h"	
#include "Controller.h"


DataDisplay::DataDisplay(/*int level*/)
	: m_players(NUM_OF_PLAYERS, Button(*Resources::instance().getPlayerFaceTexture(Player::Heavy), sf::Vector2f(PLAYER_FACE_SIZE, PLAYER_FACE_SIZE))), 
	  m_levelActions(2, Button(*Resources::instance().getLevelActionButtonTexture(LevelActions::Pause), sf::Vector2f(PLAYER_FACE_SIZE, PLAYER_FACE_SIZE))),
      m_btnsAudio(Resources::instance().getAudioClick())
{
	createPlayersButtons();
	initActionsButtons();
	createTexts();
}

DataDisplay::~DataDisplay()
{}

void DataDisplay::createPlayersButtons()
{
	float margin = 20.f;
	auto offset_x = 900;
	auto offset_y = 50;

	for (int i = 0; i < m_players.size(); i++)
	{
		auto y = floor(i / m_players.size());
		auto x = i % m_players.size();

		float size = (i == static_cast<int>(Player::Heavy)) ? PLAYER_FACE_SIZE + 10 : PLAYER_FACE_SIZE;

		m_players[i].setPosition({ offset_x + (size + margin) * float(x), offset_y + (size + margin) * float(y) });
		m_players[i].setSize(sf::Vector2f(PLAYER_FACE_SIZE, PLAYER_FACE_SIZE));
		m_players[i].setTexture(Resources::instance().getPlayerFaceTexture(Player(i)));
		m_players[i].setColor(i == static_cast<int>(Player::Heavy) ? sf::Color::White : sf::Color(255, 255, 255, 100));
	}
}

void DataDisplay::initActionsButtons()
{
	m_levelActions[static_cast<int>(LevelActions::Retry)].setPosition(sf::Vector2f(30, 30));
	m_levelActions[static_cast<int>(LevelActions::Retry)].setTexture(Resources::instance().getLevelActionButtonTexture(LevelActions::Retry));

	m_levelActions[static_cast<int>(LevelActions::Pause)].setPosition(sf::Vector2f(130, 30));
	m_levelActions[static_cast<int>(LevelActions::Pause)].setTexture(Resources::instance().getLevelActionButtonTexture(LevelActions::Pause));
}

void DataDisplay::createTexts()
{
	m_timerText.setFont(*Resources::instance().getFont());
	m_timerText.setCharacterSize(CHAR_SIZE);
	m_timerText.setPosition(1330, 45);
	m_timerText.setFillColor(sf::Color::Black);
}

void DataDisplay::draw(sf::RenderWindow& window)
{
	drawBtns(window);
	window.draw(m_timerText);
	if (!m_timer.isTimerPaused())
		setTimeText();
}

void DataDisplay::resetTimer()
{
	m_timer.startClock();
}

void DataDisplay::startTimer()
{
	m_timer.start();
}

void DataDisplay::drawBtns(sf::RenderWindow &window)
{
	for (auto& player : m_players)
	{
		player.draw(window);
	}
	for (auto& la : m_levelActions)
	{
		la.draw(window);
	}
}

void DataDisplay::setTimeText()
{
	int sec = static_cast<int>(m_timer.getTime()), min = 0;
	calcTime(sec, min);

	std::string time = (min < 10 ? "0" : "") + std::to_string(min) + ":" + (sec < 10 ? "0" : "") + std::to_string(sec);
	m_timerText.setString("Time: " + time);
}

void DataDisplay::handleClick(const sf::Event &event , GameScreen& gs)
{
	if (m_levelActions[static_cast<int>(LevelActions::Pause)].isContain(event))
	{
		m_btnsAudio.playAudio();
		gs.updateStatus(LevelActions::Pause);
		pauseTimer();
	}
	else if (m_levelActions[static_cast<int>(LevelActions::Retry)].isContain(event))
	{
		m_btnsAudio.playAudio();
		gs.retryLevel();
	}
}

void DataDisplay::setCurrPlayer(int activePlayer)
{
	for (int i = 0; i < m_players.size(); i++)
	{
		if (i == activePlayer)
		{
			m_players[activePlayer].setColor(sf::Color(sf::Color::White));
			m_players[activePlayer].setSize(sf::Vector2f(PLAYER_FACE_SIZE + 10, PLAYER_FACE_SIZE + 10));
		}
		else
			m_players[i].setColor(sf::Color(255, 255, 255, 100));
			m_players[i].setSize(sf::Vector2f(PLAYER_FACE_SIZE, PLAYER_FACE_SIZE));
	}
}

int DataDisplay::getTime()
{
    return  static_cast<int>(m_timer.getTime());
}

void DataDisplay::pauseTimer()
{
    m_timer.pause();
}

void DataDisplay::handleHover(const sf::Vector2f& location)
{
    for (int i = 0; i < m_levelActions.size(); ++i)
    {
        if (m_levelActions[i].isHover(location))
            m_levelActions[i].setColor(sf::Color({ 240, 240, 240 }));
        else
            m_levelActions[i].setColor(sf::Color::White);
    }
}
