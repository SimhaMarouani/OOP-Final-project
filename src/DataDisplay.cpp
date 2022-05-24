#include "DataDisplay.h"	
#include "Controller.h"


DataDisplay::DataDisplay(/*int level*/)
{
	m_barBackground.setSize(sf::Vector2f(DATA_DISPLAY_WIDTH, DATA_DISPLAY_HEIGHT));
	m_barBackground.setFillColor(sf::Color::White);

	m_levelText.setFont(*Resources::instance().getFont());
	m_levelText.setCharacterSize(CHAR_SIZE);
	m_levelText.setPosition(100, 50);
	m_levelText.setColor(sf::Color::Black);
	m_levelText.setString("Level: " + std::to_string(1));	//simha: need to get the number of the level from anoother class

	m_timerText.setFont(*Resources::instance().getFont());
	m_timerText.setCharacterSize(CHAR_SIZE);
	m_timerText.setPosition(350, 50);
	m_timerText.setColor(sf::Color::Black);

}

DataDisplay::~DataDisplay()
{}


void DataDisplay::draw(sf::RenderWindow& window)
{
	setTimeText();
	window.draw(m_levelText);
	window.draw(m_timerText);
}

void DataDisplay::resetTimer()
{
	m_timer.startClock();
}

void DataDisplay::calcTime(int& sec, int& min) const
{
	sec = int(m_timer.getTime());

	if (sec >= 60)
	{
		min = sec / 60;
		sec = sec % 60;
	}
}

void DataDisplay::setTimeText()
{
	int sec = 0, min = 0;
	calcTime(sec, min);

	std::string time = (min < 10 ? "0" : "") + std::to_string(min) + ":" + (sec < 10 ? "0" : "") + std::to_string(sec);
	m_timerText.setString("Time: " + time);
}