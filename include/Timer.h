#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "Macros.h"


class Timer
{
public:
	Timer(int time);
	~Timer() = default;

	//Set Functions
	void setTime(int time);
	void startClock();
	void addTime(float time_to_add);

	//Access Functions
	sf::Time getElapsed()const;
	float getTime()const;
	//timer_type getType()const;

private:
	sf::Clock m_clock;
	sf::Time m_time;
	//timer_type m_timerType;
};

