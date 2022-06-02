#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Button.h"
#include "Window.h"
#include "Settings.h"

#include "Macros.h"
#include "Utilities.h"

class Window;

//HomeMenu
class HomePageScreen
{
public:
	HomePageScreen();
	void draw(sf::RenderWindow &window);
	void processEvents(sf::Event event, Controller& controller);
	void handleClick(sf::Event event, Controller& controller);
	void initSettings(std::shared_ptr<Settings> s);

private:
	void setHelpScreen();
	void initButtons();
	void drawMenu(sf::RenderWindow& window);

	sf::RectangleShape m_helpBackground;
	std::vector<Button> m_buttons; //Noga: unique ptr?

	sf::RectangleShape m_background;

	enum class PageStatus
	{
		Menu,
		Help,
		Settings
	};

	PageStatus m_pageStatus;
	std::shared_ptr<Settings> m_settingsView;
};