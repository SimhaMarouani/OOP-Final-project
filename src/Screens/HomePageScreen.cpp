#include "Screens/HomePageScreen.h"
#include "Controller.h"

HomePageScreen::HomePageScreen()
{
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

void HomePageScreen::handleClick(sf::Event event, Controller &controller)
{
	if (m_buttons[(int)HomeButtonType::Start].isContain(event))
	{
		std::cout << "Button clicked: start\n";
		controller.updatePage(Page::LevelMenu);
	}
	else if (m_buttons[(int)HomeButtonType::Help].isContain(event))
	{
		std::cout << "Button clicked: help\n";
		//controller.openHelp()
		
	}
	else if (m_buttons[(int)HomeButtonType::Settings].isContain(event))
	{
		std::cout << "Button clicked: settings\n";
		//controller.openSettings();
	}
	else if (m_buttons[(int)HomeButtonType::Exit].isContain(event))
	{
		std::cout << "Button clicked: exit byeeeeeeeeeeeeeeee\n";
		controller.exit();
	}
}
