#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Button.h"
#include "Audio.h"

#include "Macros.h"
#include "Resources.h"
#include "Utilities.h"

#include <iostream>

class Controller;

class Settings {
public:
	Settings();
	virtual ~Settings() = default;

	void draw(sf::RenderWindow& window, enum ScreenType s);
	void update(enum ScreenType s);

	void handleClick(const sf::Event& event, enum ScreenType s);
    void handleHover(const sf::Vector2f& location);

	bool isContainExit(const sf::Event& e) const;
	bool isContainHome(const sf::Event& e) const;

private:
	void createBtns();
	void initSoundButton();
	void initTextButton();

	enum class Type
	{
		Audio = 0,
		Music
	};

	ScreenType m_currScreen;
	sf::RectangleShape m_shadow;
	sf::RectangleShape m_background;
	
	std::vector<Button> m_soundBtns;

	Button m_exitSettingsBtn; // "return"/"continue" 
	Button m_redirectBtn; // in game = "home"

	Audio m_btnsAudio;
};
