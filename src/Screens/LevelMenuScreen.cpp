#include "Screens/LevelMenuScreen.h"
#include "Controller.h" 


LevelMenuScreen::LevelMenuScreen()
	: Screen(Resources::instance().getBackground(ScreenType::LevelMenu)),
	  m_levels(NUM_OF_LEVELS , TitledButton(*Resources::instance().getLevelMenuTexture(LevelState::Lock), sf::Vector2f(LEVEL_MENU_BTN_SIZE, LEVEL_MENU_BTN_SIZE), "", 50.f, sf::Vector2f(0.f,0.f), *Resources::instance().getFont())),
	  m_numOfLevelsCompleted(HighScore::instance().getNumOfCompleteLevels()),
      m_homeButton(*Resources::instance().getBackArrowTexture()),
	  m_animation(Resources::instance().getPlayerSpriteSheet(Player::Light), sf::Vector2u(5, 8), 0.08f), //animation.
	  m_highScoreButton(*Resources::instance().getHighScoreBtn()),
	m_isScoreOpen(false)
{
	initBtns();	

	m_light.setTexture(*Resources::instance().getPlayerSpriteSheet(Player::Light)); //animation
	m_light.setScale(sf::Vector2f(0.6, 0.6)); //animation
	m_light.setPosition(sf::Vector2f(1430, 339)); //animation


	m_highScoreButton.setPosition(sf::Vector2f((WINDOW_WIDTH - m_highScoreButton.getSize().x) / 2, WINDOW_HEIGHT - m_highScoreButton.getSize().y - 100));

}

void LevelMenuScreen::draw(sf::RenderWindow& window)
{
	Screen::draw(window);
	for (auto& l : m_levels)
	{
		l.draw(window);
	}
	window.draw(m_light);
    m_homeButton.draw((window));
	m_highScoreButton.draw(window);
	if (m_isScoreOpen) m_highScoreView.draw(window);
}

void LevelMenuScreen::processEvents(sf::Event event, sf::Vector2f& mouseLocation, Controller& controller)
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
		handleHover(mouseLocation);
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

	else if (!m_isScoreOpen)
	{
		for (int i = 0; i < m_levels.size(); i++)
		{
			if (m_levels[i].isContain(event) && i <= m_numOfLevelsCompleted)
			{
				//m_btnsAudio.playAudio();
				playClickAudio();
				controller.startGame(ScreenType::Game, i+1);
			}
		}

		if (m_homeButton.isContain(event))
		{
			playClickAudio();
			controller.updatePage(ScreenType::HomePage);
		}

		if (m_highScoreButton.isContain(event))
		{
			playClickAudio();
			m_highScoreView.updateData();
			m_isScoreOpen = true;
		}
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

void LevelMenuScreen::handleHover(const sf::Vector2f& location)
{
	if (m_isScoreOpen) return;

	for (int i = 0; i <= m_numOfLevelsCompleted; ++i)
	{
		if (m_levels[i].isHover(location))
		{
			m_levels[i].setColor(sf::Color({ 255, 255, 255, 180 }));
		}
		else
		{
			m_levels[i].setColor(sf::Color::White);
		}
	}

	if (m_homeButton.isHover(location))
		m_homeButton.setColor(sf::Color({ 255, 255, 255, 180 }));
	else
		m_homeButton.setColor(sf::Color::White);

	if (m_highScoreButton.isHover(location))
		m_highScoreButton.setColor(sf::Color({ 255, 255, 255, 180 }));
	else
		m_highScoreButton.setColor(sf::Color::White);
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
