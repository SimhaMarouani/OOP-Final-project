#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Macros.h"
#include "Resources.h"
#include "Utilities.h"
#include "HighScore.h"


#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

class HighScoreView {
public:
	HighScoreView();
	void draw(sf::RenderWindow& window);

	//get
	bool isContain(sf::Event event) const;
	void setLevelScore(int level);

	void updateData();


private:
	sf::RectangleShape m_shadow; //Noga: optional
	sf::RectangleShape m_background;

	std::vector<sf::Text> m_levelsScoreText;
};
