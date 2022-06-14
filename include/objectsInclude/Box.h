#pragma once
#include "objectsInclude/StaticObjects.h"
#include "Audio.h"

class Box : public StaticObjects
{
public:
	Box(sf::Vector2f pos, b2World* world, sf::Vector2f scale);
	void playAudio();

private:
	Audio m_audio;

};