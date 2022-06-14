#pragma once
#include "GameObjects.h"


class StaticObjects : public GameObjects
{
public:
	StaticObjects();
	StaticObjects(Objects type, sf::Vector2f pos, sf::Vector2f scale); //for sensor ONLY objects
	StaticObjects(Objects type, b2World* world, sf::Vector2f pos, sf::Vector2f scale); //for objects that user can push around
	StaticObjects(Grounds type, b2World* world, sf::Vector2f pos, sf::Vector2f scale); //for "floor-like" objects - platforms etc

	void initIcon(sf::Vector2f pos, sf::Vector2f scale);
private:
};