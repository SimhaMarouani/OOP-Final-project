#include "Screens/HomePageScreen.h"
#include "Controller.h"

HomePageScreen::HomePageScreen()
	: m_pageStatus(PageStatus::Menu), m_helpBackground(sf::Vector2f(HELP_WIDTH, HELP_HEIGHT))
{
	setHelpScreen();

	m_background.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
	m_background.setTexture(Resources::instance().getBackground(Backgrounds::menu));
	// 
	//m_buttons.resize(int(ButtonType::Exit) + 1);
	m_buttons.emplace_back(Button(HOME_BTN_SIZE));
	m_buttons.emplace_back(Button(HOME_BTN_SIZE));
	m_buttons.emplace_back(Button(HOME_BTN_SIZE));
	m_buttons.emplace_back(Button(HOME_BTN_SIZE));

	auto centered_x = (WINDOW_WIDTH - HOME_BTN_SIZE.x) / 2;
	for (size_t i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i].setPosition(sf::Vector2f(centered_x, 200 + (HOME_BTN_SIZE.y + 30)* i));
		m_buttons[i].setColor(sf::Color::White);
	}

	//------------ TEMP ----------------------------------
	m_startText.setFont(*Resources::instance().getFont());
	m_startText.setCharacterSize(CHAR_SIZE);
	m_startText.setPosition(750, 220);
	m_startText.setColor(sf::Color::Blue);
	m_startText.setString("Start");

	m_helpText.setFont(*Resources::instance().getFont());
	m_helpText.setCharacterSize(CHAR_SIZE);
	m_helpText.setPosition(750, 350);
	m_helpText.setColor(sf::Color::Blue);
	m_helpText.setString("Help");

	m_setText.setFont(*Resources::instance().getFont());
	m_setText.setCharacterSize(CHAR_SIZE);
	m_setText.setPosition(720, 480);
	m_setText.setColor(sf::Color::Blue);
	m_setText.setString("Settings");

	m_exitText.setFont(*Resources::instance().getFont());
	m_exitText.setCharacterSize(CHAR_SIZE);
	m_exitText.setPosition(760, 620);
	m_exitText.setColor(sf::Color::Blue);
	m_exitText.setString("Exit");
	//--------------------------------------------------
}

void HomePageScreen::draw(sf::RenderWindow& window)
{
	window.draw(m_background);

	switch (m_pageStatus)
	{
	case PageStatus::Help:
		window.draw(m_helpBackground);
		break;
	case PageStatus::Settings:
		m_settingsScreen.draw(window);
		break;
	case PageStatus::Menu:
	default:
		drawMenu(window);
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
			controller.updatePage(Page::LevelMenu);
	
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
		if (!m_settingsScreen.isContain(event))
			m_pageStatus = PageStatus::Menu;
		break;
	}
	default:
		break;
	}
}

void HomePageScreen::setHelpScreen()
{
	auto offset_x = (WINDOW_HEIGHT - HELP_HEIGHT) / 2;
	auto offset_y = (WINDOW_WIDTH - HELP_WIDTH) / 2;
	m_helpBackground.setPosition(offset_y, offset_x);
	m_helpBackground.setFillColor(sf::Color(164, 220, 224, 250));
}

void HomePageScreen::drawMenu(sf::RenderWindow& window)
{
	for (auto& b : m_buttons)
	{
		b.draw(window);
	}
	//------- Temp
	window.draw(m_startText);
	window.draw(m_helpText);
	window.draw(m_setText);
	window.draw(m_exitText);
}
