#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

#include "Window.h"
#include "Button.h"

#include "Macros.h"
#include "Utilities.h"


class LevelMenuScreen
{
public:
	LevelMenuScreen();
	void draw(sf::RenderWindow& window);
	void handleClick(sf::Event event, Controller& controller);

private:
	std::vector<Button> m_levels;

};