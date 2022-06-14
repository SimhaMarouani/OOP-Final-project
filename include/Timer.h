#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Timer
{
public:
	Timer();
	~Timer() = default;

	void startClock();
	float getTime()const;
	bool isTimerPaused();
	void pause();
	void start();
private:
	float m_runTime;
	sf::Clock m_clock;
	bool m_pauseTimer;
};

