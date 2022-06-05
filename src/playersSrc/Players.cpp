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
{
	m_icon.setTexture(*Resources::instance().getPlayerTexture(type));
	m_icon.setScale(sf::Vector2f(0.5, 0.5)); //Tali: get from file
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
	fixture.isSensor = true;
	footSensor = m_body->CreateFixture(&fixture);
	
}


void Players::move(float deltaTime)
{
	if (m_direction == Direction::Left || m_direction == Direction::Right)
	{
		auto step1= b2Vec2(getDirection(m_direction).x * m_speedPerSecond, 0); //running speed = 300
		m_body->ApplyForceToCenter(step1, true);
		//auto step2 = b2Vec2(getDirection(m_direction).x*5, 0); //running speed = 300
		//m_body->ApplyLinearImpulse(step2, m_body->GetPosition(), true);
	}
	else
		m_body->SetLinearVelocity(b2Vec2(m_body->GetLinearVelocity().x * 0.95, m_body->GetLinearVelocity().y));

	
	//deaccelerating 
	float MAX_SPEED = 20.0f;
	if (m_body->GetLinearVelocity().x < -MAX_SPEED) {
		m_body->SetLinearVelocity(b2Vec2(-MAX_SPEED, m_body->GetLinearVelocity().y));
	}
	else if (m_body->GetLinearVelocity().x > MAX_SPEED) {
		m_body->SetLinearVelocity(b2Vec2(MAX_SPEED, m_body->GetLinearVelocity().y));
	}


	bool below = false;

	if (!m_jumping)
		return;

	//std::cout << "jumping\n";
	for (b2ContactEdge* ce = m_body->GetContactList(); ce != nullptr; ce = ce->next) {
		b2Contact* c = ce->contact;
		if (c->IsTouching()) {
			b2WorldManifold manifold;
			c->GetWorldManifold(&manifold);
			// Check if the points are below
			below = false;
			int i;
			for ( i = 0; i < b2_maxManifoldPoints; i++) {
				if (manifold.points[i].y > (m_body->GetPosition().y + (getHeight() / 2.0f) - 1.0f)) {
					if (footSensor->TestPoint(manifold.points[i]))
					{
						std::cout << "CONTACT WITH FOOT\n";
					}
					below = true;
					break;
				}
			}
			if (below && m_jumping/*sf::Keyboard::isKeyPressed(sf::Keyboard::Up)*/ /*&& footSensor->TestPoint(manifold.points[i])*/) {
				std::cout << "we can jump\n";
				auto impulse = m_body->GetMass() * 50;
				m_body->ApplyLinearImpulse(b2Vec2(0, -impulse), m_body->GetWorldCenter(), true);
				below = m_jumping = false;	
				break;
			}
		}
	}
	

	m_icon.setPosition(convertB2VecToVec2f(m_body->GetPosition()));

}


void Players::setDirection(Direction dir)
{
	m_direction = dir;
	if (dir == Direction::Up)
		m_jumping = true;
}

void Players::update()
{
	m_icon.setPosition(convertB2VecToVec2f(m_body->GetPosition())); //Tali: to possibly remove
	//direction idle?

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
