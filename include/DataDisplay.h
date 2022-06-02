#pragma once

#include "Timer.h"
//#include "TitledButton.h"
#include "Button.h"

#include "Resources.h"
#include "Macros.h"

#include <SFML/Graphics.hpp>
#include <string>

class GameScreen;

class DataDisplay
{
public:
	DataDisplay();
	~DataDisplay();
	void draw(sf::RenderWindow& window);
	void handleClick(sf::Event event, GameScreen &gs);
	//void handleHover(const sf::Vector2f& location);
	void setCurrPlayer(int activePlayer);

	//Time functiona
	void resetTimer();

private:
	void createPlayersButtons();
	void initActionsButtons();
	void createTexts();
	void calcTime(int& sec, int& min)const;
	void drawBtns(sf::RenderWindow& window);
	void setTimeText();

private:
	Timer m_timer;

	sf::Text m_scoreText;
	sf::Text m_timerText;
	sf::Text m_levelText;

	std::vector<Button> m_players;
	std::vector<Button> m_levelActions;

	sf::RectangleShape m_pauseWindow; //Noga: delete
};