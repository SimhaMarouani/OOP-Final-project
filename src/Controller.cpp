#include "Controller.h"


Controller::Controller() 
	: m_window(), m_homePageScreen(), m_currPage(Page::HomePage), m_currPlayer(0)
{
	//setWorld();
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
//
//void Controller::setWorld()
//{
//	b2Vec2 gravity(0.0f, 10.0f);
//	m_world = std::make_unique<b2World>(gravity);
//}

void Controller::startGame(Page page, int level)
{
	m_gameScreen.resetTimer();
	m_gameScreen.loadLevel(level);
	updatePage(page);
}

void Controller::updatePage(Page page)
{
	m_currPage = page;
}

void Controller::exit()
{
	m_window.close();
}

//Noga: not in use - i think we can delete it maybe (?? ? ?    :|   ? )
void Controller::resetTimer()
{
	m_gameScreen.resetTimer();
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
			processEventsLevelMenu(event);
			break;
		case Page::Game:
			processEventsGame(event);
			
			break;
		default:
			break;
		}

		if (m_currPage == Page::Game)
			handleKeyboardPress();
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

void Controller::processEventsLevelMenu(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
	{
		m_levelMenuScreen.handleClick(event, *this);
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

	//Noga: maybe we can move this to m_gameScreen.processEvents?
	if (m_gameScreen.isEscPressed())
	{
		m_currPage = Page::HomePage;
		//drawCurrPage(); //Noga: we can put this in comments because here we just update the page and after that its already calls to 'render' = draw all
	}

}

void Controller::update()
{
	
	//sf::Clock clock;
	float deltaTime = m_timer.restart().asSeconds();
	//move, update etc.
	switch (m_currPage)
	{
	case Page::HomePage:
		break;
	case Page::LevelMenu:
		break;
	case Page::Game:
		m_gameScreen.update(deltaTime);
		//m_world.getWorld()->DebugDraw();
		break;
	default:
		break;
	}
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
		m_window.drawLevelMenuPage(m_levelMenuScreen);
		break;
	case Page::Game:
		m_window.drawGame(m_gameScreen);
		break;
	default:
		break;
	}
}

void Controller::handleKeyboardPress()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_gameScreen.setDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_gameScreen.setDirection(Direction::Right);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) //Tali: Up will have to be in poll event, boop
	{
		m_gameScreen.setDirection(Direction::Up);
	}
	else
	{
		m_gameScreen.setDirection(Direction::None);
	}
}
