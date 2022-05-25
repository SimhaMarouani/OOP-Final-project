#include "Macros.h"
#include "GameObjects.h"

GameObjects::GameObjects()
{
}

void GameObjects::setBox2d(std::unique_ptr<b2World> &world, b2BodyType bodyType)
{
    // BodyDef
    b2BodyDef bodyDef;
    bodyDef.type = bodyType;

    bodyDef.position.Set(getPosition().x, getPosition().y);

    m_body = world->CreateBody(&bodyDef);

    b2PolygonShape BoxShape;
    BoxShape.SetAsBox(getWidth() / 2, getHeight() / 2);

    // FixtureDef
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &BoxShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 1.0f;

    m_body->CreateFixture(&fixtureDef);
}

float GameObjects::getWidth()
{
    return m_sprite.getGlobalBounds().width;
}

float GameObjects::getHeight()
{
    return m_sprite.getGlobalBounds().height;
}
