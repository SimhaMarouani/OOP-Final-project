#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Button.h"
#include "Window.h"
#include "SettingsScreen.h"

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

private:
	void setHelpScreen();
	void drawMenu(sf::RenderWindow& window);
	SettingsScreen m_settingsScreen;
	sf::RectangleShape m_helpBackground;
	std::vector<Button> m_buttons; //Noga: unique ptr?

	//--------Temporarley-------
	sf::Text m_startText;
	sf::Text m_helpText;
	sf::Text m_setText;
	sf::Text m_exitText;
	//--------------------------

	sf::RectangleShape m_background;

	enum class PageStatus
	{
		Menu,
		Help,
		Settings
	};

	PageStatus m_pageStatus;
	/*sf::RectangleShape m_startGameBtn;
	sf::RectangleShape m_helpBtn;
	sf::RectangleShape m_settingsBtn;
	sf::RectangleShape m_exitBtn;*/
};