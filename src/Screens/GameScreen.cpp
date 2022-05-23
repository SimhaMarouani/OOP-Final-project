#include "GameBoard.h"


GameBoard::GameBoard()
{
}

//-----------------------------------------------------------------

void GameBoard::draw(sf::RenderWindow& window)
{
	m_board.draw(window);
	m_dataDisplay.draw(window);
}

//-----------------------------------------------------------------

Btns GameBoard::handleClick(const sf::Event& event, GameStatus& status)
{

}

//-----------------------------------------------------------------

void GameBoard::handleHover(sf::Vector2f location)
{

}


//-----------------------------------------------------------------

void GameBoard::update(float deltaTime)
{

}
