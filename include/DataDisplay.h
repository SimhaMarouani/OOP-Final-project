#pragma once

#include "Timer.h"
#include "Button.h"
#include "Audio.h"

#include "Resources.h"
#include "Utilities.h"
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
	void handleClick(const sf::Event &event, GameScreen &gs);
	void handleHover(const sf::Vector2f& location);
	void setCurrPlayer(int activePlayer);

	//Time functiona
	void resetTimer();
	void startTimer();
	void pauseTimer();
    int getTime();

private:
	void createPlayersButtons();
	void initActionsButtons();
	void createTexts();
	void drawBtns(sf::RenderWindow& window);
	void setTimeText();

	Timer m_timer;

	sf::Text m_timerText;

	std::vector<Button> m_players;
	std::vector<Button> m_levelActions;

	Audio m_btnsAudio;
};