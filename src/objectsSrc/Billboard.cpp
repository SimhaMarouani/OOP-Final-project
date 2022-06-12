#include "objectsInclude/Billboard.h"

Billboard::Billboard(sf::Vector2f pos, b2World* world, sf::Vector2f scale)
	: StaticObjects(Objects::Billboard, pos, scale)
{
	//BodyDef
	b2BodyDef bodyDef;
	bodyDef.position.Set(getPosition().x, getPosition().y);
	m_body = world->CreateBody(&bodyDef);

	createSensor(world, getWidth() / 2, getHeight() / 2, b2Vec2(0, 0), 2);
}
