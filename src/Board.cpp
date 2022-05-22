#include "Board.h"


Board::Board() 
{

	

	//init players positions (function in gameObject?)
	m_heavyPlayer.setPostition(sf::Vector2f(300, 300));
	m_lightPlayer.setPostition(sf::Vector2f(500, 300));
	m_simplePlayer.setPostition(sf::Vector2f(1000, 300));

}

void Board::draw(sf::RenderWindow& window)
{
	m_heavyPlayer.draw(window);
	m_lightPlayer.draw(window);
	m_simplePlayer.draw(window);

}
