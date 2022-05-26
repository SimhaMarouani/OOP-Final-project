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
	m_icon.setPosition(pos);
}

void Players::move(float deltaTime)
{
	//if (getDirection() != b2Vec2(0, 0))
	{
		//m_body->ApplyLinearImpulseToCenter(getDirection(), true);
		auto pos = m_body->GetTransform();
		//m_body->SetTransform(b2Vec2(pos * deltaTime * m_speedPerSecond), 0);
		m_icon.setPosition(convertB2VecToVec2f(m_body->GetPosition()));
		//m_icon.setPosition(float(m_body->GetPosition().x / 100), float(m_body->GetPosition().y / 100));
		//m_icon.move(convertB2VecToVec2f(getDirection()) * m_speedPerSecond * deltaTime);
	}
}

void Players::setDirection(Direction dir)
{
	m_body->ApplyLinearImpulseToCenter(getDirection(dir), true);
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
        return b2Vec2(0, 5);
    default:
        return b2Vec2(0, 0);
    }
}

void Players::createBody(b2World* world/*, b2BodyType bodyType*/)
{
	// BodyDef
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	float x = getPosition().x;
	float y = getPosition().y;
	
	bodyDef.position.Set(/*10.0f, 10.0f*/x, y);
	//m_body->ApplyLinearImpulseToCenter(b2Vec2(x / 100, y / 100), true);
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

