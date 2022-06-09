#include "playersInclude/Players.h"

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
	shape.SetAsBox(getWidth() /2 *0.5, 6, b2Vec2(0, getHeight()/2 + 1), 0);

	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.density = 1.0f;
	fixture.friction = 0.1f;
	fixture.isSensor = true;
	footSensor = m_body->CreateFixture(&fixture);
	footSensor->SetUserData((void*)1);
}
namespace
{
	sf::Vector2f dirFromKey()
	{
		sf::Vector2f dir = { 0 , 0 };

		static const
			std::initializer_list<std::pair<sf::Keyboard::Key, sf::Vector2f>>
			keyToVectorMapping =
		{
			{ sf::Keyboard::Right, { 1, 0 } },
			{ sf::Keyboard::Left , { -1, 0 } },
			{ sf::Keyboard::Space   , { 0, -1 } },
		};

		for (const auto& pair : keyToVectorMapping)
		{
			if (sf::Keyboard::isKeyPressed(pair.first))
			{
				dir += pair.second;
			}
		}
		return dir;
		//return dir + sf::Vector2f{ 0, 0 };
	}
}


void Players::move(float deltaTime)
{
	if (/*dirFromKey() == sf::Vector2f{ 0, -1 } &&*/ dirFromKey().y < 0 && m_touchingFloor)
	{
		//auto impulse = m_body->GetMass() * 60;
		//m_body->ApplyLinearImpulse(b2Vec2(0, -impulse), m_body->GetWorldCenter(), true);
		//m_body->ApplyLinearImpulseToCenter(b2Vec2(0, -impulse),true);

		auto impulse = m_body->GetMass();
		m_body->SetLinearVelocity(b2Vec2(0, -impulse));
		m_touchingFloor = false;
	}
	auto step1 = b2Vec2(dirFromKey().x * m_body->GetMass() * m_speedPerSecond, 0);
	m_body->ApplyForceToCenter(step1, true);

}

void Players::setTouchingFloor(bool touching)
{
	m_touchingFloor = touching;
}

Direction Players::getDir(sf::Vector2f dir) const
{
	//if(dir == )
	return Direction();
}


void Players::setDirection(Direction dir)
{
	//m_direction = dir;
}

void Players::update()
{
	float MAX_SPEED = 15.0f;
	if (m_body->GetLinearVelocity().x < -MAX_SPEED) {
		m_body->SetLinearVelocity(b2Vec2(-MAX_SPEED, m_body->GetLinearVelocity().y));
	}
	else if (m_body->GetLinearVelocity().x > MAX_SPEED) {
		m_body->SetLinearVelocity(b2Vec2(MAX_SPEED, m_body->GetLinearVelocity().y));
	}
}

//b2Vec2 Players::getDirection(Direction dir)
//{
//    switch (dir)
//    {
//    case Direction::Left:
//        return b2Vec2(-1, 0);
//    case Direction::Right:
//        return b2Vec2(1, 0);
//    case Direction::Up:
//        return b2Vec2(0, -5);
//    default:
//        return b2Vec2(0, 0);
//    }
//}
