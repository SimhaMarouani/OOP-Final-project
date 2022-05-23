#include "Timer.h"

//create timer if time == -1 and else countdown
Timer::Timer()
	: m_time(sf::seconds(-1)), m_clock()/*, m_timerType(TIMER)*/
{
	setTime(-1);
	//m_timerType = time == MINUS_ONE ? TIMER : COUNTDOWN;
}

//-----------------------------------------------------------------

void Timer::setTime(int time)
{
	m_time = sf::seconds((float)time);
}

//-----------------------------------------------------------------

void Timer::startClock()
{
	m_clock.restart();
}

//-----------------------------------------------------------------

sf::Time Timer::getElapsed()const
{
	return m_clock.getElapsedTime();
}

//-----------------------------------------------------------------

void Timer::addTime(float time_to_add)
{
	sf::Time t = sf::seconds(time_to_add);
	auto sumSec = m_time.asSeconds() + t.asSeconds();
	m_time = sf::seconds(sumSec < 0 ? 0 : sumSec);
}

//-----------------------------------------------------------------

float Timer::getTime()const
{
	return m_clock.getElapsedTime().asSeconds();
	
}

