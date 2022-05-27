#include "Controller.h"


Controller::Controller() 
	: m_window(), m_homePageScreen(), m_currPage(Page::HomePage), m_currPlayer(0)
{
	//setWorld();
}

void Controller::run()
{
	srand(time(NULL));
	
	while (m_window.isOpen())
	{
		processEvents(); //events
		update(); //updates of data CLOCK AND DELTA TIME HERE
		render(); //draw
	}
}

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

void Controller::processEvents()
{
	if (auto event = sf::Event{}; m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();

		switch (m_currPage)
		{
		case Page::HomePage:
			m_homePageScreen.processEvents(event, *this);
			break;
		case Page::LevelMenu:
			m_levelMenuScreen.processEvents(event, *this);
			break;
		case Page::Game:
			m_gameScreen.processEvents(event, *this);
			break;
		default:
			break;
		}
	}
	if (m_currPage == Page::Game)
		handleKeyboardPress();
}

//void Controller::processEventsHome(sf::Event event)
//{
//	
//}
//
//void Controller::processEventsLevelMenu(sf::Event event)
//{
//}
//
//void Controller::processEventsGame(sf::Event event)
//{
//}

void Controller::update()
{
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
	//Noga: maybe we can put all the screens class in vector or something and then we wont need all the switch case ? 
	switch (m_currPage)
	{
	case Page::HomePage:
		m_window.drawScreen(m_homePageScreen); //Noga: this is the template function - works. 
		//m_window.drawHomePage(m_homePageScreen);
		break;
	case Page::LevelMenu:
		m_window.drawScreen(m_levelMenuScreen); 
		//m_window.drawLevelMenuPage(m_levelMenuScreen);
		break;
	case Page::Game:
		m_window.drawScreen(m_gameScreen); 
		//m_window.drawGame(m_gameScreen);
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
