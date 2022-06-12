#pragma once
#include "StaticObjects.h"
#include "objectsInclude/Door.h"


class Switch : public StaticObjects
{
public:
	Switch(sf::Vector2f pos, b2World* world, sf::Vector2f scale);

	void setDoor(StaticObjects* dr);
	void setPressed(bool pressed);
private:
	Door* m_door = nullptr;
	bool m_pressed;
};