#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Button.h"
#include "Window.h"

#include "Macros.h"
#include "Utilities.h"

class Window;

//HomeMenu
class Menu 
{
public:
	Menu();
	void draw(sf::RenderWindow &window);
	HomeButtonType handleClick(sf::Event event, Controller& controller);


private:
	std::vector<Button> m_buttons;

	//-------Temporarley
	sf::Text m_startText;
	sf::Text m_helpText;
	sf::Text m_setText;
	sf::Text m_exitText;

	/*sf::RectangleShape m_startGameBtn;
	sf::RectangleShape m_helpBtn;
	sf::RectangleShape m_settingsBtn;
	sf::RectangleShape m_exitBtn;*/
};