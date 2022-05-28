#include "playersInclude/Players.h"

Players::Players()
{}

Players::Players(Player type)
{
	m_icon.setTexture(*Resources::instance().getPlayerTexture(type));
	m_icon.setScale(sf::Vector2f(0.5, 0.5));
	m_icon.setOrigin(m_icon.getGlobalBounds().width, m_icon.getGlobalBounds().height);
}

void Players::draw(sf::RenderWindow& window)
{
	window.draw(m_icon);
}

void Players::setPostition(sf::Vector2f pos)
{
	//Tali: add exception to vector
	m_icon.setPosition(pos);
}

void Players::move(float deltaTime)
{
	//if (getDirection(m_direction) == b2Vec2(0, 5))
	auto impulse = m_body->GetMass() * 3;
	m_body->ApplyLinearImpulse(b2Vec2(0, impulse), m_body->GetWorldCenter(), true);

	auto step = (deltaTime * m_speedPerSecond * getDirection(m_direction));
	m_body->SetTransform(m_body->GetPosition() + step, 0);
	m_icon.setPosition(convertB2VecToVec2f(m_body->GetPosition()));
		
}

void Players::setDirection(Direction dir)
{
	m_direction = dir;
}

b2Vec2 Players::getDirection(Direction dir)
{
    switch (dir)
    {
    case Direction::Left:
        return b2Vec2(-1, 0);
    case Direction::Right:
        return b2Vec2(1, 0);
    case Direction::Up:
        return b2Vec2(0, -10);
    default:
        return b2Vec2(0, 0);
    }
}

void Players::createBody(b2World* world/*, b2BodyType bodyType*/)
{
	// BodyDef
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	/*bodyDef.type = b2_staticBody;		// for the static objects*/
	
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

float Players::getWidth()
{
	return m_icon.getGlobalBounds().width;
}

float Players::getHeight()
{
	return m_icon.getGlobalBounds().height;
}

sf::Vector2f Players::getPosition()
{
	return m_icon.getPosition();
}

