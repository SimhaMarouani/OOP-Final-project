#pragma once

#include "Timer.h"
//#include "TitledButton.h"
#include "Button.h"

#include "Resources.h"
#include "Macros.h"

#include <SFML/Graphics.hpp>
#include <string>


class DataDisplay
{
public:
	DataDisplay();
	~DataDisplay();
	void draw(sf::RenderWindow& window);
	void handleClick(sf::Event event);
	//void handleHover(const sf::Vector2f& location);
	int getCurrPlayer();
	void setCurrPlayer(int activePlayer);

	//Time functiona
	void resetTimer();

private:
	void createPlayersButtons();
	void createTexts();
	void calcTime(int& sec, int& min)const;

	void setTimeText();
	Timer m_timer;

	//sf::RectangleShape m_barBackground; //Noga: still not in use

	sf::Text m_scoreText;
	sf::Text m_timerText;
	sf::Text m_levelText;

	std::vector<Button> m_players;
	int m_pressedPlayer;
};