#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Macros.h"
#include "Button.h"
#include "Resources.h"
#include "Utilities.h"

#include <iostream>

class Controller;

class Settings {
public:
	Settings();
	virtual ~Settings() = default;
	void draw(sf::RenderWindow& window, Screen s);

	bool isContain(sf::Event event) const;
	void handleClick(sf::Event event, Screen s);

	bool isContainExit(sf::Event e) const;
	bool isContainHome(sf::Event e) const;
private:
	void createBtns();

private:
	enum class Type
	{
		Audio = 0,
		Music
	};

	bool m_audioStatus;
	sf::RectangleShape m_shadow; //Noga: optional
	sf::RectangleShape m_background;
	
	std::vector<Button> m_soundBtns;

	Button m_exitSettingsBtn; // "return" 
	Button m_redirectBtn; // in game = "home"

};
