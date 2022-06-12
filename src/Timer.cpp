#include "Timer.h"

Timer::Timer()
	: m_clock(), m_pauseTimer(false), m_runTime(0)
{
}

//-----------------------------------------------------------------

void Timer::startClock()
{
	m_clock.restart();
	m_runTime = 0;
	m_pauseTimer = false;
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

//-----------------------------------------------------------------

void Timer::pause()
{
	if (!m_pauseTimer)
		m_runTime += m_clock.getElapsedTime().asSeconds();
	m_pauseTimer = true;
}

//-----------------------------------------------------------------

void Timer::start()
{
	if (m_pauseTimer)
		m_clock.restart();
	m_pauseTimer = false;
}

//-----------------------------------------------------------------

float Timer::getTime()const
{
	if (!m_pauseTimer)
		return m_runTime + m_clock.getElapsedTime().asSeconds();
	return m_runTime;
}

