#include "Screens/LevelMenuScreen.h"
#include "Controller.h" // Noga: I dont know why but if I put this line to header file bad things happened

LevelMenuScreen::LevelMenuScreen()
	: m_levels(10 , TitledButton(sf::Vector2f(150.f, 150.f), "level1", 40.f, sf::Vector2f(0.f,0.f), *Resources::instance().getFont()))
{
	initBtns();	
}

void LevelMenuScreen::draw(sf::RenderWindow& window)
{
	for (auto& l : m_levels)
	{
		l.draw(window);
	}
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

void LevelMenuScreen::handleClick(sf::Event event, Controller& controller)
{
	for (int i = 0; i < m_levels.size(); i++)
	{
		if (m_levels[i].isContain(event) && i < m_numOfLevelsCompleted)
		{
			controller.startGame(Page::Game, i+1);
		}
	}
}

void LevelMenuScreen::initBtns()
{
	const float size = 150.f;
	const float margin = 80.f;

	int num_of_rows = floor(int(m_levels.size()) / LEVEL_MENU_COLS);
	auto offset_x = (WINDOW_WIDTH - (size + margin) * LEVEL_MENU_COLS) / 2;
	auto offset_y = (WINDOW_HEIGHT - (size + margin) * num_of_rows) / 2;


	for (int i = 0; i < m_levels.size(); i++)
	{
		auto y = floor(i / LEVEL_MENU_COLS);
		auto x = i % LEVEL_MENU_COLS;

		m_levels[i].setPosition({ offset_x + (size + margin) * float(x), offset_y + (size + margin) * float(y) });
		m_levels[i].setTextPosition({ offset_x + (size + margin) * float(x), offset_y + (size + margin) * float(y) });
		m_levels[i].setColor(i < m_numOfLevelsCompleted ? sf::Color(30, 30, 30) : sf::Color(200, 200, 200)); //if level complete = different color
		m_levels[i].setTextColor(sf::Color(130, 200, 130));
		m_levels[i].setTextString("level" + std::to_string(i + 1));
	}
}
