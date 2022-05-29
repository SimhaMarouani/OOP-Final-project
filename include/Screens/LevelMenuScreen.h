#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

#include "Window.h"
#include "TitledButton.h"

#include "Macros.h"
#include "Utilities.h"


class LevelMenuScreen
{
public:
	LevelMenuScreen();
	void draw(sf::RenderWindow& window);
	void processEvents(sf::Event event, Controller& controller);
	void handleClick(sf::Event event, Controller& controller);

private:
	void initBtns();
	int m_numOfLevelsCompleted = 3; //Noga: change to read from file which levels the user already complete and the time it took - to know for the level score....
									// maybe we need to save this in different class but for now, you know

	sf::RectangleShape m_background;
	std::vector<TitledButton> m_levels;

};