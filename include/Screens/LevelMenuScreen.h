#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

#include "Window.h"
#include "TitledButton.h"
#include "HighScore.h"
#include "Button.h"
#include "Audio.h"

#include "Macros.h"
#include "Utilities.h"


class LevelMenuScreen
{
public:
	LevelMenuScreen();
	void draw(sf::RenderWindow& window);
	void processEvents(sf::Event event, Controller& controller);
	void update(float deltaTime);
	void handleClick(sf::Event event, Controller& controller);
	void updateNumOfLevels();
private:
	void playAudio(Audio& a);
	void initBtns();
	int m_numOfLevelsCompleted; //Noga: change to read from file which levels the user already complete and the time it took - to know for the level score....
									// maybe we need to save this in different class but for now, you know

	sf::RectangleShape m_background;
	std::vector<TitledButton> m_levels;

    Button m_homeButton;
	Audio m_btnsAudio;


	//
	sf::Sprite m_light;  //animation
	Animation m_animation;  //animation
};