#pragma once
#include "GameObjects.h"



class StaticObjects : public GameObjects
{
public:
	StaticObjects();
	StaticObjects(Objects type, b2World* world, sf::Vector2f pos);
	StaticObjects(Grounds type, b2World* world, sf::Vector2f pos);

	void update();
private:
};