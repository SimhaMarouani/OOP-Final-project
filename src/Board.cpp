#include "Board.h"
#include "Controller.h"


Board::Board()
{
	//init players positions based on level file
	m_heavyPlayer.setPostition(sf::Vector2f(0, 625));
	m_lightPlayer.setPostition(sf::Vector2f(150, 625));
	m_simplePlayer.setPostition(sf::Vector2f(250, 625));

	//init objects and their positions based on level file
	m_leftblock.setSize(sf::Vector2f(400, 150));
	m_rightblock.setSize(sf::Vector2f(400, 150));
	m_leftblock.setPosition(sf::Vector2f(0, WINDOW_HEIGHT - 150));
	m_rightblock.setPosition(sf::Vector2f(WINDOW_WIDTH - 400, WINDOW_HEIGHT - 150));
	m_leftblock.setFillColor(sf::Color::Blue);
	m_rightblock.setFillColor(sf::Color::Blue);

}

void Board::draw(sf::RenderWindow& window)
{
	m_heavyPlayer.draw(window);
	m_lightPlayer.draw(window);
	m_simplePlayer.draw(window);

	window.draw(m_leftblock);
	window.draw(m_rightblock);
}

void Board::setActiveDirection(Direction dir)
{
	m_heavyPlayer.setDirection(dir);
}

void Board::moveActive(float deltaTime)
{
	m_heavyPlayer.move(deltaTime);
}
