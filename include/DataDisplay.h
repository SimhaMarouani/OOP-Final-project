#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Resources.h"
#include "Macros.h"

//class Controller;


class DataDisplay
{
public:
    DataDisplay();
	~DataDisplay();
	void draw(sf::RenderWindow& window);
	void updateLevel(int time, int level);
	void decreaseTime();
	void stopTimer();
	void continueTimer();
	bool isTimerStopped() const;
	void startTimer();

private:
	void updateTime();

	sf::Clock m_Timer;
	sf::Time m_stageTime;

	float m_stageTimeSec;

	bool m_stopTimer;

	sf::RectangleShape m_barBackground;

	sf::Text m_scoreText;
	sf::Text m_stageTimeText;
	sf::Text m_levelText;
};