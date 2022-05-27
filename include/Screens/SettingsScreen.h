#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

#include "Window.h"

#include "Macros.h"
#include "Utilities.h"


class SettingsScreen
{
public:
	SettingsScreen();
	void draw(sf::RenderWindow& window);
	void processEvents(sf::Event event);
	void handleClick(sf::Event event, Controller& controller);

	bool isContain(sf::Event event);

private:
	sf::RectangleShape m_background;


};