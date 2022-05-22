#include "Controller.h"


Controller::Controller() 
	: m_window(), m_homePage(), m_dataDisplay(), m_currPage(Page::HomePage)
{
}

void Controller::run()
{
	srand(time(NULL));
	//setGameIcon(window);
	//GameBoard gameBoard(MAX_BLOCK_TILES);

	m_dataDisplay.updateLevel(1);
	
	while (m_window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Controller::updatePage(Page page)
{
	m_currPage = page;
}

void Controller::exit()
{
	m_window.close();
}

void Controller::processEvents()
{
	if (auto event = sf::Event{}; m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();

		switch (m_currPage)
		{
		case Page::HomePage:
			processEventsHome(event);
			break;
		case Page::LevelMenu:

		case Page::Game:

		default:
			break;
		}
	}
}

void Controller::processEventsHome(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
	{
		m_homePage.handleClick(event, *this);
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

void Controller::update()
{
}

void Controller::render()
{
	m_window.clear(sf::Color(224, 235, 229));
	drawCurrPage();
	m_window.display();
}

void Controller::drawCurrPage()
{
	switch (m_currPage)
	{
	case Page::HomePage:
		m_window.drawHomePage(m_homePage);
		break;
	case Page::LevelMenu:
		m_window.drawLevelMenuPage();
		break;
	case Page::Game:
		m_window.drawGame(m_dataDisplay, &m_board);
		break;
	default:
		break;
	}
}
