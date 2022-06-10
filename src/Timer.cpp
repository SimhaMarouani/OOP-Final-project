#include "Timer.h"

Timer::Timer()
	: m_time(sf::seconds(-1)), m_clock(), m_pauseTimer(false), m_runTime(0)
{
	setTime(-1);
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
	m_runTime = 0;
}

//-----------------------------------------------------------------

void Timer::switchTimer()
{
	m_pauseTimer = !m_pauseTimer;
}

//-----------------------------------------------------------------

bool Timer::isTimerPaused()
{
	return m_pauseTimer;
}

void Timer::pause()
{
	if (!m_pauseTimer)
		m_runTime += m_clock.getElapsedTime().asSeconds();
	m_pauseTimer = true;
}

void Timer::start()
{
	if (m_pauseTimer)
		m_clock.restart();
	m_pauseTimer = false;
}

//-----------------------------------------------------------------

//sf::Time Timer::getElapsed()const
//{
//	if (m_pauseTimer)
//		return m_runTime + m_clock.getElapsedTime().asSeconds();
//	return m_runTime;
//}

//-----------------------------------------------------------------
////Simha: not used for now
//void Timer::addTime(float time_to_add)
//{
//	sf::Time t = sf::seconds(time_to_add);
//	auto sumSec = m_time.asSeconds() + t.asSeconds();
//	m_time = sf::seconds(sumSec < 0 ? 0 : sumSec);
//}

//-----------------------------------------------------------------

float Timer::getTime()const
{
	if (!m_pauseTimer)
		return m_runTime + m_clock.getElapsedTime().asSeconds();
	return m_runTime;
}

