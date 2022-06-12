#include "objectsInclude/Switch.h"

Switch::Switch(sf::Vector2f pos, b2World* world, sf::Vector2f scale)
	: StaticObjects(Objects::Switch, pos, scale), m_pressed(false)
{
	//BodyDef
	b2BodyDef bodyDef;
	bodyDef.position.Set(getPosition().x, getPosition().y);
	m_body = world->CreateBody(&bodyDef);

	createSensor(world, getWidth() / 2, getHeight() / 2, b2Vec2(0, 0), 2);
	m_body->SetUserData(this);
}


void Switch::setDoor(StaticObjects* dr)
{
	if(auto obj = static_cast<Door*>(dr))
		m_door = obj;
}

void Switch::setPressed(bool pressed)
{
	if (pressed == m_pressed)
		return;

	m_pressed = pressed;
	if (m_pressed)
	{
		std::cout << "pressed down\n";
		//change photo
	}
	else
	{
		std::cout << "switch opened\n";

		//change photo
	}
	//clicking sound
	m_door->setOpen(pressed);
}
