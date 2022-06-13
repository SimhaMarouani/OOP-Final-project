#include "Controller.h"

//bool fullscreen;


Controller::Controller() 
	: m_window(), m_homePageScreen(), m_currPage(Screen::HomePage)
{
	std::shared_ptr s = std::make_shared<Settings>();
	std::shared_ptr w = std::make_shared<EndLevelScreen>();
	m_homePageScreen.initSettings(s);
	m_gameScreen.initSettings(s);
	m_gameScreen.initEndLevelScreen(w);
}

void Controller::run()
{
	srand(time(NULL));
	Resources::instance().playMusic(m_currPage);
	//fullscreen = 0;
	/*sf::View view;
	view = m_window.getView();
	view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	view.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	m_window.setView(view);*/

	while (m_window.isOpen())
	{
		processEvents(/*view*/); //events
		update(); //updates of data CLOCK AND DELTA TIME HERE
		render(); //draw
	}
	HighScore::instance().save();

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

void Controller::processEvents(/*sf::View &view*/)
{
	if (auto event = sf::Event{}; m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();

		//if (event.type == sf::Event::Resized)
		//{
		//	//glViewport(0, 0, 640, 480);
		//	m_window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().bitsPerPixel), "SFML Graphics", sf::Style::Fullscreen);
		//	//view = m_window.getView();
		//	//view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		//	//view.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

		//	view = sf::View(sf::FloatRect(0.f, 0.f, WINDOW_WIDTH, WINDOW_HEIGHT));
		//	auto size = sf::VideoMode::getDesktopMode();
		//	view.setViewport({ 0.f, 0.f, (float)size.width, (float)size.height });
		//	m_window.setView(view);
		//}

		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			if (fullscreen) m_window.create(sf::VideoMode::getFullscreenModes()[0], GAME_TITLE);
			//if (fullscreen) m_window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().BitsPerPixel), "SFML Graphics", sf::Style::Fullscreen);
			if (!fullscreen) m_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_WIDTH), GAME_TITLE);
			fullscreen = !fullscreen;
		}*/

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


void Controller::updateNumOfLevels()
{
	m_levelMenuScreen.updateNumOfLevels();
}
