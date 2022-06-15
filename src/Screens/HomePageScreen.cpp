#include "Screens/HomePageScreen.h"
#include "Controller.h"

HomePageScreen::HomePageScreen()
	: Screen(Resources::instance().getBackground(ScreenType::HomePage)),
	m_pageStatus(PageStatus::Menu), m_helpBackground(sf::Vector2f(HELP_WIDTH, HELP_HEIGHT)),
	m_animation(Resources::instance().getPlayerSpriteSheet(Player::Heavy), sf::Vector2u(5, 5), 0.08f) //animation
{
	setHelpScreen();

	m_heavy.setTexture(*Resources::instance().getPlayerSpriteSheet(Player::Heavy)); //animation
	m_heavy.setPosition(sf::Vector2f(140, 500)); //animation

	initButtons();

}

void HomePageScreen::draw(sf::RenderWindow& window)
{
	Screen::draw(window);
	window.draw(m_heavy);
	switch (m_pageStatus)
	{
	case PageStatus::Help:
		window.draw(m_helpBackground);
		break;
	case PageStatus::Settings:
		m_settingsView->draw(window, ScreenType::HomePage);
		break;
	case PageStatus::Menu:
		drawMenu(window);
	default:
		break;
	}
}

void HomePageScreen::processEvents(const sf::Event& event, sf::Vector2f &mouseLocation, Controller& controller)
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
        m_settingsView->handleHover(mouseLocation);
		break;
	}
	default:
		break;
	}
}

void HomePageScreen::handleClick(const sf::Event &event, Controller &controller)
{
	switch (m_pageStatus)
	{
	case HomePageScreen::PageStatus::Menu:
	{
		handleMenuClick(event, controller);
		break;
	}
	case HomePageScreen::PageStatus::Help:
	{
		if (!m_helpBackground.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		{
			setBackgroundColor(sf::Color(255, 255, 255));
			m_pageStatus = PageStatus::Menu;
		}
		break;
	}
	case HomePageScreen::PageStatus::Settings:
	{
		m_settingsView->handleClick(event, ScreenType::HomePage);
		if (m_settingsView->isContainExit(event))
		{
			playClickAudio();
			m_pageStatus = PageStatus::Menu;
		}
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
	if (m_pageStatus == PageStatus::Settings)
	{
		m_settingsView->update(ScreenType::HomePage);
	}
	m_animation.update(1 /*line*/, 5, deltaTime, true); //animation
	m_heavy.setTextureRect(m_animation.m_uvRect); //animations
}

void HomePageScreen::handleMenuClick(const sf::Event& event, Controller& controller)
{
	if (m_buttons[static_cast<int>(HomeButtonType::Start)].isContain(event))
	{
		playClickAudio();
		controller.updatePage(ScreenType::LevelMenu);
		controller.updateNumOfLevels();
	}

	else if (m_buttons[static_cast<int>(HomeButtonType::Help)].isContain(event))
	{
		playClickAudio();
		setBackgroundColor(sf::Color(255, 255, 255, 205));
		m_pageStatus = PageStatus::Help;
	}
	else if (m_buttons[static_cast<int>(HomeButtonType::Settings)].isContain(event))
	{
		playClickAudio();
		m_pageStatus = PageStatus::Settings;
	}
	else if (m_buttons[static_cast<int>(HomeButtonType::Exit)].isContain(event))
	{
		playClickAudio();
		controller.exit();
	}
}

void HomePageScreen::setHelpScreen()
{
	auto offset_x = (WINDOW_HEIGHT - HELP_HEIGHT) / 2;
	auto offset_y = (WINDOW_WIDTH - HELP_WIDTH) / 2;
	m_helpBackground.setPosition(offset_y, offset_x);
	m_helpBackground.setTexture(Resources::instance().getHelpBackground());
	m_helpBackground.setFillColor(sf::Color({ 255,255,255,250 }));
}

void HomePageScreen::initButtons()
{
	m_buttons.emplace_back(Button(*Resources::instance().getHomePageBtnsTexture(HomeButtonType::Start), 1));
	m_buttons.emplace_back(Button(*Resources::instance().getHomePageBtnsTexture(HomeButtonType::Help), 1));
	m_buttons.emplace_back(Button(*Resources::instance().getHomePageBtnsTexture(HomeButtonType::Settings), 1));
	m_buttons.emplace_back(Button(*Resources::instance().getHomePageBtnsTexture(HomeButtonType::Exit), 1));

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

void HomePageScreen::handleHover(const sf::Vector2f& location)
{
    for (int i = 0; i < m_buttons.size(); ++i)
    {
        if (m_buttons[i].isHover(location))
			m_buttons[i].setColor(sf::Color({ 240, 240, 240}));
        else
			m_buttons[i].setColor(sf::Color::White);
    }
}