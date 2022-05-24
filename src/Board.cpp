#include "Board.h"
#include "Controller.h"


Board::Board()
{
	//init players positions based on level file
	initPlayers();

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
	for (auto& movable : m_players)
	{
		movable.draw(window);
	}
	window.draw(m_leftblock);
	window.draw(m_rightblock);
}

void Board::setActiveDirection(Direction dir, Player active)
{
	m_players[(int)active].setDirection(dir);
}

void Board::moveActive(float deltaTime, Player active)
{
	m_players[(int)active].move(deltaTime);
}

void Board::initPlayers()
{
	Heavy heavy;
	Simple simple;
	Light light;

	heavy.setPostition(sf::Vector2f(0, 625));
	light.setPostition(sf::Vector2f(150, 625));
	simple.setPostition(sf::Vector2f(250, 625));

	m_players.emplace_back(heavy);
	m_players.emplace_back(simple);
	m_players.emplace_back(light);
	
}
