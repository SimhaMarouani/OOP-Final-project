#include "Controller.h"


Controller::Controller() 
	: m_window(), m_homePageScreen(), m_currPage(Screen::HomePage)
{
	std::shared_ptr s = std::make_shared<Settings>();
	std::shared_ptr w = std::make_shared<WinScreen>();
	m_homePageScreen.initSettings(s);
	m_gameScreen.initSettings(s);
	m_gameScreen.initEndLevelScreen(w);
}

void Controller::run()
{
	srand(time(NULL));
	Resources::instance().playMusic(m_currPage);

	while (m_window.isOpen())
	{
		processEvents(); //events
		update(); //updates of data CLOCK AND DELTA TIME HERE
		render(); //draw
	}
}

void Controller::startGame(Screen page, int level)
{
	m_gameScreen.resetTimer();
	m_gameScreen.loadLevel(level);
	updatePage(page);
}

void Controller::updatePage(Screen page)
{
	m_currPage = page;
	changeMusic(page);
}

void Controller::exit()
{
	m_window.close();
}

void Controller::changeMusic(Screen s)
{
	if (Resources::instance().isMusicOn())
		Resources::instance().playMusic(s);
}

void Controller::processEvents()
{
	if (auto event = sf::Event{}; m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();

		switch (m_currPage)
		{
		case Screen::HomePage:
			m_homePageScreen.processEvents(event, *this);
			break;
		case Screen::LevelMenu:
			m_levelMenuScreen.processEvents(event, *this);
			break;
		case Screen::Game:
			m_gameScreen.processEvents(event, *this);
			break;
		default:
			break;
		}
	}
	////Noga: we need to check if we can move this handlekeyboard to the gameScreen processEvents
	//if (m_currPage == Screen::Game && m_gameScreen.getPageStatus() != LevelActions::Pause)
	//	handleKeyboardPress();
}


void Controller::update()
{
	//Tali:maybe here step
	float deltaTime = m_timer.restart().asSeconds();
	//move, update etc.etc.etc.
	switch (m_currPage)
	{
	case Screen::HomePage:
		m_homePageScreen.update(deltaTime); //animation
		break;
	case Screen::LevelMenu:
		m_levelMenuScreen.update(deltaTime);
		break;
	case Screen::Game:
		m_gameScreen.update(deltaTime);
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
	case Screen::HomePage:
		m_window.drawScreen(m_homePageScreen);
		break;
	case Screen::LevelMenu:
		m_window.drawScreen(m_levelMenuScreen); 
		break;
	case Screen::Game:
		m_window.drawScreen(m_gameScreen); 
		break;
	default:
		break;
	}
}

void Controller::handleKeyboardPress()
{
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	//{
	//	m_gameScreen.setDirection(Direction::Left);
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	//{
	//	m_gameScreen.setDirection(Direction::Right);
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) //Tali: Up will have to be in poll event, boop
	//{
	//	m_gameScreen.setDirection(Direction::Up);
	//}
	//else
	//{
	//	m_gameScreen.setDirection(Direction::None);
	//}
}

void Controller::updateNumOfLevels()
{
	m_levelMenuScreen.updateNumOfLevels();
}
