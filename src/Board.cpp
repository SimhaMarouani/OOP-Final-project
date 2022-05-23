#include "Board.h"
#include "Controller.h"


Board::Board() 
{
	//init players positions (function in gameObject?)
	m_heavyPlayer.setPostition(sf::Vector2f(300, 600));
	m_lightPlayer.setPostition(sf::Vector2f(500, 600));
	m_simplePlayer.setPostition(sf::Vector2f(1000, 600));
}

void Board::draw(sf::RenderWindow& window)
{
	m_heavyPlayer.draw(window);
	m_lightPlayer.draw(window);
	m_simplePlayer.draw(window);
}

void Board::createObject(Controller& controller)
{
	controller.createPlayersVec();
}