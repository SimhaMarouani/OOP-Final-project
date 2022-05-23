#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "Timer.h"

#include "Resources.h"
#include "Macros.h"

//class Controller;


class DataDisplay
{
public:
    DataDisplay();
	~DataDisplay();
	void draw(sf::RenderWindow& window);

	//Time functiona
	void resetTimer();

private:

	void calcTime(int& sec, int& min)const;

	void drawTime(sf::RenderWindow& window);
	Timer m_timer;

	sf::RectangleShape m_barBackground; //Noga: still not in use

	sf::Text m_scoreText;
	sf::Text m_timerText;
	sf::Text m_levelText;
};