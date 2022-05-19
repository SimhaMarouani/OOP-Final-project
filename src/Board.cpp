#include "Board.h"

const b2Vec2 gravity = b2Vec2(0.0f, 10.0f);

Board::Board() 
{
	// Construct a world object, which will hold and simulate the rigid bodies.
	// Use dynamic allocation as this is a big object, and allocating it on the stack
	auto world = std::make_unique<b2World>(gravity);

	m_groundBodyDef.position.Set(0.0f, -10.0f);

}
