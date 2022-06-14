#include "GameObjects.h"

GameObjects::GameObjects()
{
}

GameObjects::~GameObjects()
{
    m_body->GetWorld()->DestroyBody(m_body);
}


void GameObjects::createSquareBody(b2World* world, b2BodyType bodyType, sf::Vector2i rect)
{
    //BodyDef
    b2BodyDef bodyDef;
    bodyDef.type = bodyType;
    bodyDef.position.Set(getPosition().x, getPosition().y);
    bodyDef.linearDamping = 0.0f;
    bodyDef.angularDamping = 0.4f;

    m_body = world->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    float width = rect.x == 0 ? getWidth() : float(rect.x) / 2;
    float height = rect.y == 0 ? getHeight() : float(rect.y) / 2;

    boxShape.SetAsBox(width / 2, height / 2);

    // FixtureDef
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;
    if (bodyType == b2_dynamicBody)
    {
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
    }
    m_body->CreateFixture(&fixtureDef);
    m_body->SetUserData(this);
}

void GameObjects::createCircleBody(b2World* world, b2BodyType bodyType, float radius)
{
    //BodyDef
    b2BodyDef bodyDef;
    bodyDef.type = bodyType;
    bodyDef.position.Set(getPosition().x, getPosition().y);
    m_body = world->CreateBody(&bodyDef);

    b2CircleShape circle;
    circle.m_p.Set(0, 0);
    circle.m_radius = radius;

    // FixtureDef
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circle;
    if (bodyType == b2_dynamicBody)
    {
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
    }
    m_body->CreateFixture(&fixtureDef);
    m_body->SetUserData(this);
}


void GameObjects::createSensor(b2World* world, float width, float height, b2Vec2 center, int data)
{
    b2PolygonShape shape;
    shape.SetAsBox(width, height, center, 0);

    b2FixtureDef fixture;
    fixture.shape = &shape;
    fixture.density = 1.0f;
    fixture.friction = 0.1f;
    fixture.isSensor = true;
    m_body->CreateFixture(&fixture)->SetUserData((void*)data);
}

void GameObjects::draw(sf::RenderWindow& window)
{
    if (!m_body->IsFixedRotation()) {
        auto angle = m_body->GetAngle() * 180 / b2_pi;
        m_icon.setRotation(angle);
    }
    m_icon.setPosition(convertB2VecToVec2f(m_body->GetPosition()));
    window.draw(m_icon);
}

sf::Vector2f GameObjects::convertB2VecToVec2f(b2Vec2 vec2f) const
{
    return sf::Vector2f({ vec2f.x, vec2f.y });
}

void GameObjects::setPosition(sf::Vector2f pos)
{
    m_icon.setPosition(pos);
    if (m_body)
        m_body->SetTransform(b2Vec2(pos.x, pos.y), 0);
}

void GameObjects::updateObj()
{
    if (m_body->GetType() == b2_dynamicBody)
        m_body->SetAwake(true);

    float MAX_SPEED = 15.0f;
    if (m_body->GetLinearVelocity().x < -MAX_SPEED) {
        m_body->SetLinearVelocity(b2Vec2(-MAX_SPEED, m_body->GetLinearVelocity().y));
    }
    else if (m_body->GetLinearVelocity().x > MAX_SPEED) {
        m_body->SetLinearVelocity(b2Vec2(MAX_SPEED, m_body->GetLinearVelocity().y));
    }
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
