#include "playersInclude/Players.h"

Players::Players()
{}

Players::Players(Player type)
	:GameObjects()
{
	m_icon.setTexture(*Resources::instance().getPlayerTexture(type));
	m_icon.setScale(sf::Vector2f(0.5, 0.5));
	m_icon.setOrigin(m_icon.getGlobalBounds().width, m_icon.getGlobalBounds().height);
}

Players::Players(Player type, b2World* world)
	:m_touchingFloor(true)
{
	m_icon.setTexture(*Resources::instance().getPlayerTexture(type));
	m_icon.setScale(sf::Vector2f(0.5, 0.5)); //Tali: make default
	m_icon.setOrigin(m_icon.getGlobalBounds().width, m_icon.getGlobalBounds().height);
	m_icon.setPosition(sf::Vector2f(0, 600)); //Tali: change to DEFAULT

	//create body in world
	createBody(world, b2_dynamicBody);
	m_body->SetFixedRotation(true);

	//create foot sensor
	b2PolygonShape shape;
	shape.SetAsBox(getWidth() /2 *0.9, 10, b2Vec2(0, getHeight()/2 + 1), 0);

	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.density = 1.0f;
	fixture.friction = 0.1f;
	fixture.isSensor = true;
	footSensor = m_body->CreateFixture(&fixture);
	footSensor->SetUserData((void*)1);

}


void Players::move(float deltaTime)
{
	if (m_direction == Direction::Left || m_direction == Direction::Right)
	{
		//if with mass:
		//auto step1= b2Vec2(getDirection(m_direction).x * 300, 0); //running speed = 300
		//m_body->ApplyForceToCenter(step1, true);
		//else if without mass:
		auto step2 = b2Vec2(getDirection(m_direction).x*300, 0); //running speed = 300
		m_body->ApplyLinearImpulse(step2, m_body->GetPosition(), true);
		auto step = deltaTime * m_speedPerSecond * getDirection(m_direction);
		m_body->SetTransform(m_body->GetPosition() + step, 0);
	}
	else
		m_body->SetLinearVelocity(b2Vec2(m_body->GetLinearVelocity().x * 0.95, m_body->GetLinearVelocity().y));


	if (m_direction == Direction::Up && m_touchingFloor)
	{
		auto impulse = m_body->GetMass() * 60;
		m_body->ApplyLinearImpulse(b2Vec2(0, -impulse), m_body->GetWorldCenter(), true);
		m_touchingFloor = false;
	}
}

void Players::setTouchingFloor(bool touching)
{
	std::cout << "set touching floor to true\n";
	m_touchingFloor = touching;
}


void Players::setDirection(Direction dir)
{
	m_direction = dir;
}

void Players::update()
{
	//m_icon.setPosition(convertB2VecToVec2f(m_body->GetPosition())); //Tali: to possibly remove
	//direction idle?
	float MAX_SPEED = 15.0f;
	if (m_body->GetLinearVelocity().x < -MAX_SPEED) {
		m_body->SetLinearVelocity(b2Vec2(-MAX_SPEED, m_body->GetLinearVelocity().y));
	}
	else if (m_body->GetLinearVelocity().x > MAX_SPEED) {
		m_body->SetLinearVelocity(b2Vec2(MAX_SPEED, m_body->GetLinearVelocity().y));
	}

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
        return b2Vec2(0, -5);
    default:
        return b2Vec2(0, 0);
    }
}
