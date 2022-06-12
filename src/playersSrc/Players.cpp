#include "playersInclude/Players.h"

Players::Players(Player type, sf::Vector2u imageCount, b2World* world)
	:m_touchingFloor(true),
	m_animation(Resources::instance().getPlayerSpriteSheet(type), imageCount, 0.08f),
	m_direction(Direction::None),
	m_isFaceRight(true)
{
	//float width = m_animation.m_uvRect.width / 2;
	//float height = m_animation.m_uvRect.width/2 ;
	m_icon.setTexture(*Resources::instance().getPlayerSpriteSheet(type));
	m_icon.setScale(sf::Vector2f(0.5, 0.5)); //Tali: make default
	m_icon.setOrigin(m_animation.m_uvRect.width/2 , m_animation.m_uvRect.height/2); //m_icon.getGlobalBounds().width, m_icon.getGlobalBounds().height);
	m_icon.setPosition(sf::Vector2f(0, 600)); //Tali: change to DEFAULT

	//create body in world
	createBody(world, b2_dynamicBody, sf::Vector2i{ m_animation.m_uvRect.width  , m_animation.m_uvRect.height});

	//IF YOU WANT SHAPE TO BE CIRC
	//b2BodyDef bodyDef;
	//bodyDef.type = b2_dynamicBody;
	//bodyDef.position.Set(getPosition().x, getPosition().y);
	//m_body = world->CreateBody(&bodyDef);

	//b2CircleShape circle;
	//circle.m_p.Set(0,0);
	//circle.m_radius = m_animation.m_uvRect.height /4;

	//// FixtureDef
	//b2FixtureDef fixtureDef;
	//fixtureDef.shape = &circle;

	//fixtureDef.density = 1.0f;
	//fixtureDef.friction = 0.4f;
	//m_body->CreateFixture(&fixtureDef);
	//m_body->SetUserData(this);

	//create foot sensor
	createSensor(world, m_animation.m_uvRect.width / 4 * 0.5, 10, b2Vec2(0, m_animation.m_uvRect.height / 4 + 1), 1);
	m_body->SetFixedRotation(true);
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
	}
}


void Players::move(float deltaTime)
{
	if ( dirFromKey().y < 0 && m_touchingFloor)
		m_body->ApplyLinearImpulseToCenter(b2Vec2(0, this->getJumpImpulse()), true);

	auto step1 = b2Vec2(dirFromKey().x * m_body->GetMass() * m_speedPerSecond, 0);
	m_body->ApplyForceToCenter(step1, true);

	//move to update func
	sf::Vector2f dir = dirFromKey();
	m_direction = getDir(dir);
}

void Players::setTouchingFloor(bool touching)
{
	m_touchingFloor = touching;
}

Direction Players::getDir(sf::Vector2f dir) 
{
	if (dir.y < 0 && !m_touchingFloor)
	{
		return Direction::Up;
	}
	else if (dir.x > 0)
	{
		m_isFaceRight = true;
		return Direction::Left;

	}
	else if (dir.x < 0)
	{
		m_isFaceRight = false;
		return Direction::Right;
	}

	return Direction::None;
}

void Players::setFaceRight(bool f)
{
	m_isFaceRight = f;
}

void Players::updateAnimation(float deltaTime)
{
	//first = row, second = num of images
	std::pair<int, int> row_numOf = getAnimationData();
	m_animation.update(row_numOf.first, row_numOf.second, deltaTime, m_isFaceRight);
	m_icon.setTextureRect(m_animation.m_uvRect);
}


//Tali: to remove??
void Players::setDirection(Direction dir)
{
	//m_direction = dir;
}

void Players::update(float deltaTime)
{
	float MAX_SPEED = 15.0f;
	if (m_body->GetLinearVelocity().x < -MAX_SPEED) {
		m_body->SetLinearVelocity(b2Vec2(-MAX_SPEED, m_body->GetLinearVelocity().y));
	}
	else if (m_body->GetLinearVelocity().x > MAX_SPEED) {
		m_body->SetLinearVelocity(b2Vec2(MAX_SPEED, m_body->GetLinearVelocity().y));
	}
	updateAnimation(deltaTime);
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
