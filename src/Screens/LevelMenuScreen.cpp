#include "Screens/LevelMenuScreen.h"
#include "Controller.h" 


LevelMenuScreen::LevelMenuScreen()
	: m_levels(NUM_OF_LEVELS , TitledButton(*Resources::instance().getLevelMenuTexture(LevelState::Lock), sf::Vector2f(LEVEL_MENU_BTN_SIZE, LEVEL_MENU_BTN_SIZE), "", 50.f, sf::Vector2f(0.f,0.f), *Resources::instance().getFont())),
	  m_background(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT)),
	  m_numOfLevelsCompleted(HighScore::instance().getNumOfCompleteLevels()),
      m_homeButton(*Resources::instance().getBackArrowTexture()),
	  m_btnsAudio(Resources::instance().getAudioClick()),
	  m_animation(Resources::instance().getPlayerSpriteSheet(Player::Light), sf::Vector2u(5, 8), 0.08f), //animation.
	  m_highScoreButton(*Resources::instance().getSettingsHomeTexture()),
	m_isScoreOpen(false)
{
	m_background.setTexture(Resources::instance().getBackground(Screen::LevelMenu));
	initBtns();	

	m_light.setTexture(*Resources::instance().getPlayerSpriteSheet(Player::Light)); //animation
	m_light.setScale(sf::Vector2f(0.6, 0.6)); //animation
	m_light.setPosition(sf::Vector2f(1430, 339)); //animation


	m_highScoreButton.setPosition(sf::Vector2f((WINDOW_WIDTH - m_highScoreButton.getSize().x) / 2, WINDOW_HEIGHT - m_highScoreButton.getSize().y - 100));

}

void LevelMenuScreen::draw(sf::RenderWindow& window)
{
	window.draw(m_background);
	for (auto& l : m_levels)
	{
		l.draw(window);
	}
	window.draw(m_light);
    m_homeButton.draw((window));
	m_highScoreButton.draw(window);
	if (m_isScoreOpen) m_highScoreView.draw(window);

}

void LevelMenuScreen::processEvents(sf::Event event, Controller& controller)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
	{
		handleClick(event, controller);
		break;
	}
	case sf::Event::MouseMoved:
	{
		/*sf::Vector2f location = window.mapPixelToCoords(
			{ event.mouseMove.x, event.mouseMove.y });
		gameBoard.handleHover(location);*/
		break;
	}
	default:
		break;
	}
}

void LevelMenuScreen::update(float deltaTime)
{
	m_animation.update(1 /*line*/, 5, deltaTime, false); //animation
	m_light.setTextureRect(m_animation.m_uvRect); //animations
}

void LevelMenuScreen::handleClick(sf::Event event, Controller& controller)
{
	if (m_isScoreOpen && !m_highScoreView.isContain(event))
	{
		m_isScoreOpen = false;
		return;
	}

	for (int i = 0; i < m_levels.size(); i++)
	{
		if (m_levels[i].isContain(event) && i <= m_numOfLevelsCompleted)
		{
			m_btnsAudio.playMusic();
			controller.startGame(Screen::Game, i+1);
		}
	}

	if (m_homeButton.isContain(event))
	{
		m_btnsAudio.playMusic();
		controller.updatePage(Screen::HomePage);
	}

	if (m_highScoreButton.isContain(event))
	{
		m_btnsAudio.playMusic();
		m_isScoreOpen = true;
	}
}

void LevelMenuScreen::updateNumOfLevels()
{
	int curr = HighScore::instance().getNumOfCompleteLevels();
	for (int i = m_numOfLevelsCompleted + 1; i < curr; i++)
	{
		m_levels[i].setTexture(Resources::instance().getLevelMenuTexture(LevelState::Unlock));
		m_levels[i].setTextColor(sf::Color(64, 63, 61));
		m_levels[i].setTextString(std::to_string(i + 1));

		//high score table
		m_highScoreView.setLevelScore(i);
	}
	m_numOfLevelsCompleted = curr;
}

void LevelMenuScreen::initBtns()
{
	const float margin = 20.f;

	int num_of_rows = floor(int(m_levels.size()) / LEVEL_MENU_COLS);
	auto offset_x = (WINDOW_WIDTH - (LEVEL_MENU_BTN_SIZE + margin) * LEVEL_MENU_COLS) / 2;
	auto offset_y = (WINDOW_HEIGHT - (LEVEL_MENU_BTN_SIZE + margin) * num_of_rows) / 3;

    m_homeButton.setPosition(sf::Vector2f (30, 30));

	for (int i = 0; i < m_levels.size(); i++)
	{
		auto y = floor(i / LEVEL_MENU_COLS);
		auto x = i % LEVEL_MENU_COLS;
		auto posX = offset_x + (LEVEL_MENU_BTN_SIZE + margin) * float(x);
		auto posY = offset_y + (LEVEL_MENU_BTN_SIZE + margin) * float(y);

		m_levels[i].setPosition({ offset_x + (LEVEL_MENU_BTN_SIZE + margin) * float(x), offset_y + (LEVEL_MENU_BTN_SIZE + margin) * float(y) });
		//m_levels[i].setTextPosition({ offset_x + (size + margin) * float(x), offset_y + (size + margin) * float(y) });
		m_levels[i].setTextPosition({ posX + (LEVEL_MENU_BTN_SIZE / 3), posY + (LEVEL_MENU_BTN_SIZE / 3) });
		m_levels[i].setTexture(i <= m_numOfLevelsCompleted ? Resources::instance().getLevelMenuTexture(LevelState::Unlock) : Resources::instance().getLevelMenuTexture(LevelState::Lock));
		m_levels[i].setTextColor(sf::Color(64, 63, 61));
		m_levels[i].setTextString(i <= m_numOfLevelsCompleted ? std::to_string(i + 1) : "");
	}
}
