#pragma once
#include <SFML/Graphics.hpp>

#include "Board.h"

#include "DataDisplay.h"

class GameScreen {
public:
	GameScreen();
	void draw(sf::RenderWindow& window);
	void processEvents(sf::Event event);

	void update(float deltaTime);

	void resetTimer();
	bool isEscPressed();

private:

	enum class PlayerType
	{
		Heavy = 0,
		Simple,
		Light
	};

	Board m_board;
	DataDisplay m_dataDisplay;
	Player m_activePlayer;

	bool m_escPressed;
};