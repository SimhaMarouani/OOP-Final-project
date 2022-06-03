#include "Screens/HomePageScreen.h"
#include "Controller.h"

HomePageScreen::HomePageScreen()
	: m_pageStatus(PageStatus::Menu), m_helpBackground(sf::Vector2f(HELP_WIDTH, HELP_HEIGHT)),
	m_animation(Resources::instance().getPlayerSpriteSheet(Player::Heavy), sf::Vector2u(5, 5), 0.08f) //animation
{
	setHelpScreen();

	m_background.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
	m_background.setTexture(Resources::instance().getBackground(Screen::HomePage));

	m_heavy.setTexture(*Resources::instance().getPlayerSpriteSheet(Player::Heavy)); //animation
	m_heavy.setPosition(sf::Vector2f(140, 500)); //animation

	initButtons();

}

void HomePageScreen::draw(sf::RenderWindow& window)
{
	window.draw(m_background);
	window.draw(m_heavy);
	switch (m_pageStatus)
	{
	case PageStatus::Help:
		window.draw(m_helpBackground);
		break;
	case PageStatus::Settings:
		m_settingsView->draw(window, Screen::HomePage);
		break;
	case PageStatus::Menu:
		drawMenu(window);
	default:
		break;
	}
}

void HomePageScreen::processEvents(sf::Event event, Controller& controller)
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

void HomePageScreen::handleClick(sf::Event event, Controller &controller)
{
	switch (m_pageStatus)
	{
	case HomePageScreen::PageStatus::Menu:
	{
		if (m_buttons[(int)HomeButtonType::Start].isContain(event))
			controller.updatePage(Screen::LevelMenu);
	
		else if (m_buttons[(int)HomeButtonType::Help].isContain(event))
		{
			m_pageStatus = PageStatus::Help;
		}
		else if (m_buttons[(int)HomeButtonType::Settings].isContain(event))
			m_pageStatus = PageStatus::Settings;
		
		else if (m_buttons[(int)HomeButtonType::Exit].isContain(event))
			controller.exit();
		break;
	}
	case HomePageScreen::PageStatus::Help:
	{
		if (!m_helpBackground.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			m_pageStatus = PageStatus::Menu;
		break;
	}
	case HomePageScreen::PageStatus::Settings:
	{
		m_settingsView->handleClick(event, Screen::HomePage);
		if (!m_settingsView -> isContain(event)) //Noga: delete?
			m_pageStatus = PageStatus::Menu;
		if(m_settingsView->isContainExit(event))
			m_pageStatus = PageStatus::Menu;
		break;
	}
	default:
		break;
	}
}

void HomePageScreen::initSettings(std::shared_ptr<Settings> s)
{
	m_settingsView = move(s);
}

void HomePageScreen::update(float deltaTime)
{
	m_animation.update(1 /*line*/, 5, deltaTime); //animation
	m_heavy.setTextureRect(m_animation.m_uvRect); //animations
}

void HomePageScreen::setHelpScreen()
{
	auto offset_x = (WINDOW_HEIGHT - HELP_HEIGHT) / 2;
	auto offset_y = (WINDOW_WIDTH - HELP_WIDTH) / 2;
	m_helpBackground.setPosition(offset_y, offset_x);
	m_helpBackground.setFillColor(sf::Color(164, 220, 224, 250));
}

void HomePageScreen::initButtons()
{
	m_buttons.emplace_back(Button(*Resources::instance().getHomePageBtnsTexture(HomeButtonType::Start), HOME_BTN_SIZE));
	m_buttons.emplace_back(Button(*Resources::instance().getHomePageBtnsTexture(HomeButtonType::Help), HOME_BTN_SIZE));
	m_buttons.emplace_back(Button(*Resources::instance().getHomePageBtnsTexture(HomeButtonType::Settings), HOME_BTN_SIZE));
	m_buttons.emplace_back(Button(*Resources::instance().getHomePageBtnsTexture(HomeButtonType::Exit), HOME_BTN_SIZE));

	auto centered_x = (WINDOW_WIDTH - HOME_BTN_SIZE.x) / 2;
	for (size_t i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i].setPosition(sf::Vector2f(centered_x, 140 + (HOME_BTN_SIZE.y + 20) * i));
		m_buttons[i].setColor(sf::Color::White);
	}
}

void HomePageScreen::drawMenu(sf::RenderWindow& window)
{
	for (auto& b : m_buttons)
	{
		b.draw(window);
	}
}
