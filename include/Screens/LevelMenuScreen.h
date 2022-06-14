#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

#include "Window.h"
#include "TitledButton.h"
#include "HighScore.h"
#include "Button.h"
#include "Audio.h"
#include "HighScoreView.h"
#include "Screen.h"

#include "Macros.h"
#include "Utilities.h"


class LevelMenuScreen : public Screen
{
public:
	LevelMenuScreen();
	void draw(sf::RenderWindow& window);
	void processEvents(sf::Event event, sf::Vector2f& mouseLocation, Controller& controller);
	void update(float deltaTime);
	void handleClick(sf::Event event, Controller& controller);
	void updateNumOfLevels();
private:
	void handleHover(const sf::Vector2f& location);
	void initBtns();
	int m_numOfLevelsCompleted; //Noga: change to read from file which levels the user already complete and the time it took - to know for the level score....
									// maybe we need to save this in different class but for now, you know

	std::vector<TitledButton> m_levels;

	Button m_homeButton;
	Button m_highScoreButton;
	Audio m_btnsAudio;

	bool m_isScoreOpen;
	//
	sf::Sprite m_light;  //animation
	Animation m_animation;  //animation

	HighScoreView m_highScoreView;
};