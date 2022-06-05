#include "objectsInclude/StaticObjects.h"

StaticObjects::StaticObjects()
{
}

StaticObjects::StaticObjects(Objects type, b2World* world, sf::Vector2f pos, sf::Vector2f scale)
{
	m_icon.setTexture(*Resources::instance().getObjectTexture(type));
	m_icon.setOrigin(m_icon.getGlobalBounds().width/2, m_icon.getGlobalBounds().height/2);
	//m_icon.setScale(sf::Vector2f(0.4, 0.4));
	m_icon.setScale(scale);
	m_icon.setPosition(pos);
	createBody(world, b2_dynamicBody);

}

StaticObjects::StaticObjects(Grounds type, b2World* world, sf::Vector2f pos, sf::Vector2f scale)
{
	m_icon.setTexture(*Resources::instance().getGroundTexture(type));
	m_icon.setOrigin(m_icon.getGlobalBounds().width/2, m_icon.getGlobalBounds().height/2);
	m_icon.setScale(scale);

	//if(type == Grounds::Left_l1)
	//	m_icon.setScale(sf::Vector2f(0.95, 0.7));
	//else if (type == Grounds::l2)
	//	m_icon.setScale(sf::Vector2f(1,1));
	//else
	//	m_icon.setScale(sf::Vector2f(0.1, 0.07));
	m_icon.setPosition(pos);
	createBody(world, b2_staticBody);

}

void StaticObjects::update()
{
	m_icon.setPosition(convertB2VecToVec2f(m_body->GetPosition()));
	m_icon.rotate(m_body->GetAngle());
}


