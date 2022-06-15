#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Macros.h"
#include "Resources.h"
#include "Utilities.h"
#include "HighScore.h"

#include <iostream>
#include <vector>

class HighScoreView {
public:
	HighScoreView();
	void draw(sf::RenderWindow& window);

	//get
	bool isContain(const sf::Event& event) const;
	void setLevelScore(int level);

	void updateData();

private:
	sf::RectangleShape m_shadow;
	sf::RectangleShape m_background;

	std::vector<sf::Text> m_levelsScoreText;
};
