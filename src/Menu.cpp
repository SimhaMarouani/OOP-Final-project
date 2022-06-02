#include "Menu.h"
#include "Controller.h"

Menu::Menu()
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
}

void Menu::draw(sf::RenderWindow& window)
{
	for (auto& b : m_buttons)
	{
		b.draw(window);
	}
}

HomeButtonType Menu::handleClick(sf::Event event, Controller &controller)
{
	if (m_buttons[(int)HomeButtonType::Start].isContain(event))
	{
		std::cout << "Button clicked: start\n";
		controller.updatePage(Page::Game);
		//controller.startGame();
		return HomeButtonType::Start;
	}
	else if (m_buttons[(int)HomeButtonType::Help].isContain(event))
	{
		std::cout << "Button clicked: help\n";
		//controller.openHelp()
		return HomeButtonType::Help;
	}
	else if (m_buttons[(int)HomeButtonType::Settings].isContain(event))
	{
		std::cout << "Button clicked: settings\n";
		//controller.openSettings();
		return HomeButtonType::Settings;
	}
	else if (m_buttons[(int)HomeButtonType::Exit].isContain(event))
	{
		std::cout << "Button clicked: exit byeeeeeeeeeeeeeeee\n";
		controller.exit();
		return HomeButtonType::Exit;
	}
	else return HomeButtonType::None;
}
