#pragma once
#include "objectsInclude/StaticObjects.h"
#include "Audio.h"


class Door : public StaticObjects
{
public:
	Door(sf::Vector2f pos, Grounds type, b2World* world, sf::Vector2f scale);

	void setOpen(bool open);
	void updateDoorState();
private:
	bool m_open;
	bool m_moved;

	Audio m_audio;
};
