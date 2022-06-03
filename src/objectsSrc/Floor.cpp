#include "objectsInclude/Floor.h"

Floor::Floor(Grounds type)
	:StaticObjects(type)
{
}

Floor::Floor(sf::Vector2f pos, Grounds type)
	: StaticObjects(type)
{
	setPosition(pos);
}

void Floor::setAsGround()
{
	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.type = b2_staticBody;
	groundBodyDef.position.Set(0.f, WINDOW_HEIGHT - 150);

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	//b2Body* groundBody = m_box2dWorld.CreateBody(&groundBodyDef);
	//groundBody = m_box2dWorld.CreateBody(&groundBodyDef);

	// Define the ground box shape.
	b2PolygonShape groundBox;

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(500.0f, 2.0f);

	// Add the ground fixture to the ground body.
	//groundBody->CreateFixture(&groundBox, 0.0f);

}
