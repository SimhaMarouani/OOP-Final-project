#include "objectsInclude/Border.h"

Border::Border(b2World* world, sf::Vector2f pos, float width, float height)
{
	//BodyDef
	b2BodyDef bodyDef;
	bodyDef.position.Set(pos.x, pos.y);
	m_body = world->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(width / 2, height / 2);

    // FixtureDef
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;
    m_body->CreateFixture(&fixtureDef);
    m_body->SetUserData(this);
}
