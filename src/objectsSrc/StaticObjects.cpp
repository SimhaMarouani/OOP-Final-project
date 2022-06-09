#include "objectsInclude/StaticObjects.h"

StaticObjects::StaticObjects()
{
}

StaticObjects::StaticObjects(Objects type, b2World* world, sf::Vector2f pos, sf::Vector2f scale)
{
	m_icon.setTexture(*Resources::instance().getObjectTexture(type));
	initIcon(pos, scale);
	createBody(world, b2_dynamicBody);
	m_body->SetAngularDamping(0.1f);

}

StaticObjects::StaticObjects(Grounds type, b2World* world, sf::Vector2f pos, sf::Vector2f scale)
{
	m_icon.setTexture(*Resources::instance().getGroundTexture(type));
	initIcon(pos, scale);
	createBody(world, b2_staticBody);
}

void StaticObjects::initIcon(sf::Vector2f pos, sf::Vector2f scale)
{
	m_icon.setOrigin(m_icon.getGlobalBounds().width / 2, m_icon.getGlobalBounds().height / 2);
	m_icon.setScale(scale);
	m_icon.setPosition(pos);

}
void StaticObjects::update()
{
	//Tali: same in player
	float MAX_SPEED = 15.0f;
	if (m_body->GetLinearVelocity().x < -MAX_SPEED) {
		m_body->SetLinearVelocity(b2Vec2(-MAX_SPEED, m_body->GetLinearVelocity().y));
	}
	else if (m_body->GetLinearVelocity().x > MAX_SPEED) {
		m_body->SetLinearVelocity(b2Vec2(MAX_SPEED, m_body->GetLinearVelocity().y));
	}
	m_icon.setRotation(m_body->GetAngle());
	m_icon.setPosition(convertB2VecToVec2f(m_body->GetPosition()));

}


