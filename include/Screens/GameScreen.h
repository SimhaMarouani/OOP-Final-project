#pragma once
#include <SFML/Graphics.hpp>

#include "Board.h"

#include "DataDisplay.h"

class GameBoard {
public:
	GameBoard();
	void draw(sf::RenderWindow& window);
	Btns handleClick(const sf::Event& event, GameStatus& status);
	void handleHover(sf::Vector2f location);
	void update(float deltaTime);

private:
	Board m_board;
	DataDisplay m_dataDisplay;

};