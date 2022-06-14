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
	void processEvents(const sf::Event &event, sf::Vector2f& mouseLocation, Controller& controller);
	void update(float deltaTime);
	void handleClick(const sf::Event& event, Controller& controller);
	void updateNumOfLevels();
private:
	void handleHover(const sf::Vector2f& location);
	void initBtns();
	int m_numOfLevelsCompleted;

	std::vector<TitledButton> m_levels;

	Button m_homeButton;
	Button m_highScoreButton;

	bool m_isScoreOpen;
	
	sf::Sprite m_light;  //animation
	Animation m_animation;  //animation

	HighScoreView m_highScoreView;
};