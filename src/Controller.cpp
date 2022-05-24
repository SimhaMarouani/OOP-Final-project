#include "Controller.h"

const b2Vec2 gravity = b2Vec2(0.0f, 10.0f);

Controller::Controller() 
	: m_window(), m_homePageScreen(), m_currPage(Page::HomePage), m_currPlayer(0)
{
	auto world = std::make_unique<b2World>(gravity);

	m_groundBodyDef.position.Set(0.0f, -10.0f);
}

void Controller::run()
{
	srand(time(NULL));

	//m_dataDisplay.updateLevel(1);

	//setGameIcon(window);
	
	while (m_window.isOpen())
	{
		processEvents(); //events
		update(); //updates of data CLOCK AND DELTA TIME HERE
		render(); //draw
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

void Controller::resetTimer()
{
	m_gameScreen.resetTimer();
}

void Controller::processEvents()
{
	sf::Clock clock; //T: I think timer needs to be member

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
			break;
		case Page::Game:
			processEventsGame(event);
			
			break;
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
		m_homePageScreen.handleClick(event, *this);
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

void Controller::processEventsGame(sf::Event event)
{
	m_gameScreen.processEvents(event);

	if (m_gameScreen.isEscPressed())
	{
		m_currPage = Page::HomePage;
		drawCurrPage();
	}
}

void Controller::update()
{
	sf::Time deltaTime = m_timer.restart();
	//move, update etc.
	//gameBoard.update(deltaTime.asSeconds());
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
		m_window.drawHomePage(m_homePageScreen);
		break;
	case Page::LevelMenu:
		m_window.drawLevelMenuPage();
		break;
	case Page::Game:
		m_window.drawGame(m_gameScreen);
		break;
	default:
		break;
	}
}