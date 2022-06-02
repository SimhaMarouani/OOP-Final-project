#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Macros.h"
#include "Button.h"
#include "Resources.h"
#include "Utilities.h"

#include <iostream>

class Settings {
public:
	Settings(sf::Vector2f bgSize);
	virtual ~Settings() = default;
	void draw(sf::RenderWindow& window);

	//get
	bool isContain(sf::Event event) const;
	void handleClick(sf::Event event, Screen s);

private:
	void createBtns();

private:
	enum class Type
	{
		Audio = 0,
		Music
	};

	bool m_audioStatus;
	sf::RectangleShape m_background;
	std::vector<Button> m_soundBtns;
};
