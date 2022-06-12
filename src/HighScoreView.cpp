#include "HighScoreView.h"

HighScoreView::HighScoreView()
	: m_background(sf::Vector2f(SETTINGS_WIDTH, SETTINGS_HEIGHT)),
	m_shadow(sf::Vector2f(WINDOW_WIDTH,WINDOW_HEIGHT))
{
	m_background.setTexture(Resources::instance().getSettingsBackground());
	m_background.setPosition(sf::Vector2f((WINDOW_WIDTH - SETTINGS_WIDTH) / 2, (WINDOW_HEIGHT - SETTINGS_HEIGHT) / 2));
	m_shadow.setFillColor(sf::Color(255, 255, 255, 50));
	
	//float width;
	m_levelsScoreText.resize(NUM_OF_LEVELS);
	for (int i = 0 ; i < m_levelsScoreText.size(); i++)
	{
		m_levelsScoreText[i].setFont(*Resources::instance().getFont());
		m_levelsScoreText[i].setColor(sf::Color::Black);

		m_levelsScoreText[i].setCharacterSize(CHAR_SIZE);
		std::string scoreStr;
		int sec = HighScore::instance().getLevelScore(i+1);
		if (sec == -1)
			scoreStr = "-";
		else
		{
			int min = 0;
			calcTime(sec, min);
			scoreStr = std::to_string(min) + ":" + std::to_string(sec);
		}
		m_levelsScoreText[i].setString("Level " + std::to_string(i + 1) + "\t\t" + scoreStr);
		//width = m_levelsScoreText[i].getGlobalBounds().width;
		
		m_levelsScoreText[i].setPosition(/*(WINDOW_WIDTH - width) / 2*/ m_background.getPosition().x + 200, m_background.getPosition().y + 100 + (CHAR_SIZE + 20) * i);
	}
}

void HighScoreView::draw(sf::RenderWindow& window)
{
	window.draw(m_background);
	window.draw(m_shadow);
	for (auto& t : m_levelsScoreText)
	{
		window.draw(t);
	}
}

bool HighScoreView::isContain(sf::Event event) const
{
	return m_background.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
}

void HighScoreView::setLevelScore(int level)
{
	int sec = HighScore::instance().getLevelScore(level);
	int min = 0;
	calcTime(sec, min);
	std:: string scoreStr = std::to_string(min) + ":" + std::to_string(sec);

	m_levelsScoreText[level -1].setString("Level " + std::to_string(level) + "\t\t" + scoreStr);
}

void HighScoreView::updateData()
{
	for (int i = 0; i < m_levelsScoreText.size(); i++)
	{
		m_levelsScoreText[i].setFont(*Resources::instance().getFont());
		m_levelsScoreText[i].setColor(sf::Color::Black);

		m_levelsScoreText[i].setCharacterSize(CHAR_SIZE);
		std::string scoreStr;
		int sec = HighScore::instance().getLevelScore(i + 1);
		if (sec == -1)
			scoreStr = "-";
		else
		{
			int min = 0;
			calcTime(sec, min);
			scoreStr = std::to_string(min) + ":" + std::to_string(sec);
		}
		m_levelsScoreText[i].setString("Level " + std::to_string(i + 1) + "\t\t" + scoreStr);

		m_levelsScoreText[i].setPosition(m_background.getPosition().x + 200, m_background.getPosition().y + 100 + (CHAR_SIZE + 20) * i);
	}
}
