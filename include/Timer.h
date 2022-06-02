#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "Macros.h"


class Timer
{
public:
	Timer();
	~Timer() = default;

	//Set Functions
	void setTime(int time);
	void startClock();
	void addTime(float time_to_add);
	//TODO: add start and pause
	void start();
	void pause();
	//Access Functions
	sf::Time getElapsed()const;
	float getTime()const;

private:
	sf::Clock m_clock;
	sf::Time m_time;
};

