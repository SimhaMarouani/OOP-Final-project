#include "Controller.h"


Controller::Controller() 
	: m_window(), m_currPage(ScreenType::HomePage)
{
	std::shared_ptr s = std::make_shared<Settings>();
	std::shared_ptr w = std::make_shared<EndLevelView>();

	//init screens
	m_screens.resize(NUM_OF_BG_TEXTURES);
	m_screens[static_cast<int>(ScreenType::HomePage)] = std::make_unique<HomePageScreen>();
	m_screens[static_cast<int>(ScreenType::LevelMenu)] = std::make_unique<LevelMenuScreen>();
	m_screens[static_cast<int>(ScreenType::Game)] = std::make_unique<GameScreen>();

	//init 
	dynamic_cast<HomePageScreen*>(m_screens[static_cast<int>(ScreenType::HomePage)].get())->initSettings(s);
	dynamic_cast<GameScreen*>(m_screens[static_cast<int>(ScreenType::Game)].get())->initSettings(s);
	dynamic_cast<GameScreen*>(m_screens[static_cast<int>(ScreenType::Game)].get())->initEndLevelScreen(w);
}

void Controller::run()
{
	srand(time(NULL));
	Resources::instance().playMusic(m_currPage);

	while (m_window.isOpen())
	{
		processEvents(); //events
		update(); // data updates
		render(); //draw
	}
	HighScore::instance().save();
}

void Controller::startGame(ScreenType page, unsigned int level)
{
	dynamic_cast<GameScreen*>(m_screens[static_cast<int>(ScreenType::Game)].get())->resetTimer();
	dynamic_cast<GameScreen*>(m_screens[static_cast<int>(ScreenType::Game)].get())->loadLevel(level);
	updatePage(page);
}

void Controller::updatePage(ScreenType page)
{
	m_currPage = page;
	changeMusic(page);
}

void Controller::exit()
{
	m_window.close();
}

void Controller::changeMusic(ScreenType s) const
{
	if (Resources::instance().isMusicOn())
		Resources::instance().playMusic(s);
}

void Controller::processEvents()
{
	if (auto event = sf::Event{}; m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->exit();

		sf::Vector2f ml = m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y }); //get mouse location
		m_screens[static_cast<int>(m_currPage)]->processEvents(event, ml, *this);
	}
}

void Controller::update()
{
	float deltaTime = m_timer.restart().asSeconds();
	m_screens[static_cast<int>(m_currPage)]->update(deltaTime);
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
	case ScreenType::HomePage:
		m_window.drawScreen(dynamic_cast<HomePageScreen*>(m_screens[static_cast<int>(ScreenType::HomePage)].get()));
		break;
	case ScreenType::LevelMenu:
		m_window.drawScreen(dynamic_cast<LevelMenuScreen*>(m_screens[static_cast<int>(ScreenType::LevelMenu)].get()));
		break;
	case ScreenType::Game:
		m_window.drawScreen(dynamic_cast<GameScreen*>(m_screens[static_cast<int>(ScreenType::Game)].get()));
		break;
	default:
		break;
	}
}


void Controller::updateNumOfLevels()
{
	dynamic_cast<LevelMenuScreen*>(m_screens[static_cast<int>(ScreenType::LevelMenu)].get())->updateNumOfLevels();
}
