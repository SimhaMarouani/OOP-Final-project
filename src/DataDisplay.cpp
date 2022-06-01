#include "DataDisplay.h"	
#include "Controller.h"

DataDisplay::DataDisplay(/*int level*/)
	: m_players(NUM_OF_PLAYERS, Button(*Resources::instance().getPlayerFaceTexture(Player::Heavy), sf::Vector2f(PLAYER_FACE_SIZE, PLAYER_FACE_SIZE))), 
	  //m_pressedPlayer(0),
	  m_levelActions(2, Button(*Resources::instance().getLevelActionButtonTexture(LevelActions::Pause), sf::Vector2f(PLAYER_FACE_SIZE, PLAYER_FACE_SIZE))),
	  m_pageStatus(LevelActions::None),
	  m_pauseWindow(sf::Vector2f(800, 500))
{
	createPlayersButtons();
	createTexts();
	//m_players[m_pressedPlayer].setOutline(sf::Color::Black, 4);
	
	m_pauseWindow.setFillColor(sf::Color(30, 30, 30));
	m_pauseWindow.setPosition(sf::Vector2f((WINDOW_WIDTH - 800) / 2, (WINDOW_HEIGHT - 500) / 2));


	m_levelActions[int(LevelActions::Retry)].setPosition(sf::Vector2f(30, 30));
	m_levelActions[int(LevelActions::Retry)].setTexture(Resources::instance().getLevelActionButtonTexture(LevelActions::Retry));

	m_levelActions[int(LevelActions::Pause)].setPosition(sf::Vector2f(130, 30));
	m_levelActions[int(LevelActions::Pause)].setTexture(Resources::instance().getLevelActionButtonTexture(LevelActions::Pause));
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
		float size = (i == int(Player::Heavy)) ? PLAYER_FACE_SIZE + 10 : PLAYER_FACE_SIZE;

		m_players[i].setPosition({ offset_x + (size + margin) * float(x), offset_y + (size + margin) * float(y) });
		m_players[i].setSize(sf::Vector2f(PLAYER_FACE_SIZE, PLAYER_FACE_SIZE));
		m_players[i].setColor(i == (int)Player::Heavy ? sf::Color::White : sf::Color(255, 255, 255, 100));
	}

	for (int i = 0; i < m_players.size(); i++)
	{
		//Need to change buttons to sprite and set the texture of the buttons
		m_players[i].setTexture(Resources::instance().getPlayerFaceTexture(Player(i)));
	}
}

void DataDisplay::createTexts()
{
	m_levelText.setFont(*Resources::instance().getFont());
	m_levelText.setCharacterSize(CHAR_SIZE);
	m_levelText.setPosition(100, 50);
	m_levelText.setColor(sf::Color::Black);
	m_levelText.setString("Level: " + std::to_string(1));	//simha: need to get the number of the level from anoother class

	m_timerText.setFont(*Resources::instance().getFont());
	m_timerText.setCharacterSize(CHAR_SIZE);
	m_timerText.setPosition(350, 50);
	m_timerText.setColor(sf::Color::Black);
}

void DataDisplay::draw(sf::RenderWindow& window)
{
	setTimeText();
	//window.draw(m_levelText); //Noga: we need to decide if we neet this text and where to place it on the window
	window.draw(m_timerText);

	for (auto& player : m_players)
	{
		player.draw(window);
	}
	for (auto& la : m_levelActions)
	{
		la.draw(window);
	}

	switch (m_pageStatus)
	{
	case LevelActions::Pause:
		window.draw(m_pauseWindow);
		break;
	case LevelActions::Retry:
		break;
	case LevelActions::None:
		break;
	default:
		break;
	}
}

void DataDisplay::resetTimer()
{
	m_timer.startClock();
}

void DataDisplay::calcTime(int& sec, int& min) const
{
	sec = int(m_timer.getTime());

	if (sec >= 60)
	{
		min = sec / 60;
		sec = sec % 60;
	}
}

//void DataDisplay::handleLevelActionClicked(LevelActions la)
//{
//
//}

//void DataDisplay::isClickPlayersBtns(sf::Event event)
//{
//	for (int i = 0; i < m_players.size(); i++)
//	{
//		if (m_players[i].isContain(event))
//		{
//			m_pressedPlayer = i;
//		}
//		else
//		{
//			m_players[i].setColor(sf::Color(255, 255, 255, 190));
//			m_players[i].setSize(sf::Vector2f(PLAYER_FACE_SIZE, PLAYER_FACE_SIZE));
//		}
//	}
//	m_players[m_pressedPlayer].setColor(sf::Color(sf::Color::White));
//	m_players[m_pressedPlayer].setSize(sf::Vector2f(PLAYER_FACE_SIZE + 10, PLAYER_FACE_SIZE + 10));
//}

void DataDisplay::setTimeText()
{
	int sec = 0, min = 0;
	calcTime(sec, min);

	std::string time = (min < 10 ? "0" : "") + std::to_string(min) + ":" + (sec < 10 ? "0" : "") + std::to_string(sec);
	m_timerText.setString("Time: " + time);
}

void DataDisplay::handleClick(sf::Event event)
{
	switch (m_pageStatus)
	{
	case LevelActions::Pause:
	{
		if (!m_pauseWindow.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			m_pageStatus = LevelActions::None;
		break;
	}
	case LevelActions::Retry:
		break;
	case LevelActions::None:
	{
		//isClickPlayersBtns(event);
		//Noga: move to function
		for (int i = 0; i < m_levelActions.size() && m_pageStatus == LevelActions::None; i++)
		{
			if (m_levelActions[i].isContain(event))
			{
				if (i == int(LevelActions::Pause)) m_pageStatus = LevelActions(i);
				if (i == int(LevelActions::Retry)) std::cout << "retry\n"; //retryLevel(); //send the GameScreen

				break;
			}
		}
		break;
	}
	default:
		break;
	}

	
}

//int DataDisplay::getCurrPlayer()
//{
//	return m_pressedPlayer;
//}

void DataDisplay::setCurrPlayer(int activePlayer)
{
	for (int i = 0; i < m_players.size(); i++)
	{
		if (i == activePlayer)
		{
			//m_pressedPlayer = activePlayer;
			m_players[activePlayer].setColor(sf::Color(sf::Color::White));
			m_players[activePlayer].setSize(sf::Vector2f(PLAYER_FACE_SIZE + 10, PLAYER_FACE_SIZE + 10));
		}
		else
			m_players[i].setColor(sf::Color(255, 255, 255, 100));
			m_players[i].setSize(sf::Vector2f(PLAYER_FACE_SIZE, PLAYER_FACE_SIZE));
	}
}

//void DataDisplay::handleHover(const sf::Vector2f& location)
//{
//	for (int i = 0; i < m_players.size(); i++)
//	{
//		if (this->m_players[i].isContain(location))
//		{
//			m_players[i].setOutline(sf::Color::Black);
//		}
//		else
//		{
//			m_players[i].setOutline(WHITE_COLOR);
//		}
//	}
//}
