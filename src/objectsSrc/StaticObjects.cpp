#include "objectsInclude/StaticObjects.h"

StaticObjects::StaticObjects()
{
}

StaticObjects::StaticObjects(Objects type, sf::Vector2f pos, sf::Vector2f scale)
{
	m_icon.setTexture(*Resources::instance().getObjectTexture(type));
	initIcon(pos, scale);
}

StaticObjects::StaticObjects(Objects type, b2World* world, sf::Vector2f pos, sf::Vector2f scale)
{
	m_icon.setTexture(*Resources::instance().getObjectTexture(type));
	initIcon(pos, scale);
	createSquareBody(world, b2_dynamicBody);
}

StaticObjects::StaticObjects(Grounds type, b2World* world, sf::Vector2f pos, sf::Vector2f scale)
{
	m_icon.setTexture(*Resources::instance().getGroundTexture(type));
	initIcon(pos, scale);
	createSquareBody(world, b2_staticBody);
}

void StaticObjects::initIcon(sf::Vector2f pos, sf::Vector2f scale)
{
	m_icon.setOrigin(m_icon.getGlobalBounds().width/2, m_icon.getGlobalBounds().height/2);
	m_icon.setPosition(pos);
	m_icon.setScale(scale);
}
void StaticObjects::update()
{
	if(m_body->GetType() == b2_dynamicBody)
		m_body->SetAwake(true);
	//Tali: same in player
	float MAX_SPEED = 15.0f;
	if (m_body->GetLinearVelocity().x < -MAX_SPEED) {
		m_body->SetLinearVelocity(b2Vec2(-MAX_SPEED, m_body->GetLinearVelocity().y));
	}
	else if (m_body->GetLinearVelocity().x > MAX_SPEED) {
		m_body->SetLinearVelocity(b2Vec2(MAX_SPEED, m_body->GetLinearVelocity().y));
	}
}


