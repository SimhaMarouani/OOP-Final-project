#include "DataDisplay.h"	
#include "Controller.h"


DataDisplay::DataDisplay()
	: m_timelessLevel(false), m_timeEnd(false), m_stopTimer(false)
{
	m_barBackground.setSize(sf::Vector2f(DATA_DISPLAY_WIDTH, DATA_DISPLAY_HEIGHT));
	m_barBackground.setFillColor(sf::Color::White);

	this->m_levelText.setFont(*ResourcesManager::instance().getFont());
	this->m_levelText.setCharacterSize(CHAR_SIZE);
	this->m_levelText.setPosition(100, 140);
	this->m_levelText.setColor(sf::Color::White);

	this->m_stageTimeText.setFont(*ResourcesManager::instance().getFont());
	this->m_stageTimeText.setCharacterSize(CHAR_SIZE);
	this->m_stageTimeText.setPosition(45, 245);
	this->m_stageTimeText.setColor(sf::Color::White);
}

DataDisplay::~DataDisplay()
{}

void DataDisplay::updateTime()
{
	m_stageTimeSec += 0;
	m_stageTimeSec += this->m_Timer.getElapsedTime().asSeconds();
	int minutesCounter = ((int)this->m_stageTimeSec) / 60;
	int secondsCounter = ((int)this->m_stageTimeSec) % 60;

	std::string minString = minutesCounter < 10 ? "0" + std::to_string(minutesCounter) : std::to_string(minutesCounter);
	std::string secString = secondsCounter < 10 ? "0" + std::to_string(secondsCounter) : std::to_string(secondsCounter);

	m_stageTimeText.setString("   Timer: " + minString + ":" + secString);
	
	//m_Timer.restart();
}

void DataDisplay::draw(sf::RenderWindow& window)
{
	updateTime();
	window.draw(m_levelText);
	window.draw(m_stageTimeText);
}

void DataDisplay::updateLevel(int time, int level)
{
	m_timeEnd = false;
	if (time == -1) //if a timeless level
	{
		m_timelessLevel = true;
		m_stageTimeSec = 0;
		m_stageTimeSec++;
	}
	else
	{
		m_timelessLevel = false;
		m_stageTimeSec = time;
	}

	m_levelText.setString("Level: " + std::to_string(level));
	m_Timer.restart();
}

bool DataDisplay::timeOut() const
{
	return m_timeEnd;
}

void DataDisplay::decreaseTime()
{
	m_stageTimeSec -= m_stageTimeSec / 4;
}

void DataDisplay::increaseTime()
{
	m_stageTimeSec += 15;
}

void DataDisplay::stopTimer()
{
	m_stopTimer = true;
}

void DataDisplay::continueTimer()
{
	m_stopTimer = false;
	m_Timer.restart();
}

bool DataDisplay::isTimerStopped() const
{
	return m_stopTimer;
}

void DataDisplay::startTimer()
{
	m_Timer.restart();
}