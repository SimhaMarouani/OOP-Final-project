#include "GameObjects.h"

GameObjects::GameObjects()
{
}

GameObjects::~GameObjects()
{
    m_body->GetWorld()->DestroyBody(m_body);
}
//GameObjects::GameObjects(b2World* world, b2BodyType bodyType)
//{
//    //BodyDef
//    b2BodyDef bodyDef;
//    bodyDef.type = bodyType;
//    bodyDef.position.Set(getPosition().x, getPosition().y);
//
//    m_body = world->CreateBody(&bodyDef);
//
//    b2PolygonShape boxShape;
//    boxShape.SetAsBox(getWidth() / 2, getHeight() / 2);
//
//    // FixtureDef
//    b2FixtureDef fixtureDef;
//    fixtureDef.shape = &boxShape;
//    if (bodyType == b2_dynamicBody)
//    {
//        fixtureDef.density = 1.0f;
//        fixtureDef.friction = 1.0f;
//        b2MassData mass;
//	    mass.center = m_body->GetLocalCenter();
//	    mass.mass = 10;
//    }
//    m_body->CreateFixture(&fixtureDef);
//
//
//}


void GameObjects::draw(sf::RenderWindow& window)
{
    if (!m_body->IsFixedRotation())
        m_icon.setRotation(m_body->GetAngle());
    m_icon.setPosition(convertB2VecToVec2f(m_body->GetPosition()));
    window.draw(m_icon);
}

sf::Vector2f GameObjects::convertB2VecToVec2f(b2Vec2 vec2f) const
{
    return sf::Vector2f({ vec2f.x, vec2f.y });
}
void GameObjects::setPosition(sf::Vector2f pos)
{
    //Tali: add exception to vector
    m_icon.setPosition(pos);
    if (m_body)
        m_body->SetTransform(b2Vec2(pos.x, pos.y), 0);
}

//
void GameObjects::createBody(b2World* world, b2BodyType bodyType)
{ 
      //BodyDef
    b2BodyDef bodyDef;
    bodyDef.type = bodyType;
    bodyDef.position.Set(getPosition().x, getPosition().y);

    m_body = world->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(getWidth() / 2 /* - b2_polygonRadius*/, getHeight() / 2 /* - b2_polygonRadius*/);

    // FixtureDef
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;
    if (bodyType == b2_dynamicBody)
    {
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
    }
    m_body->CreateFixture(&fixtureDef);

}

float GameObjects::getWidth()const
{
    return m_icon.getGlobalBounds().width;
}

float GameObjects::getHeight()const
{
    return m_icon.getGlobalBounds().height;
}

sf::Vector2f GameObjects::getPosition()const
{
    return m_icon.getPosition();
}

b2Body* GameObjects::getBody()
{
    return m_body;
}
