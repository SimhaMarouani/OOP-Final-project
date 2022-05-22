#include "Board.h"

const b2Vec2 gravity = b2Vec2(0.0f, 10.0f);

Board::Board() 
{
	// Construct a world object, which will hold and simulate the rigid bodies.
	// Use dynamic allocation as this is a big object, and allocating it on the stack
	auto world = std::make_unique<b2World>(gravity);

	m_groundBodyDef.position.Set(0.0f, -10.0f);
	

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

//draw board
