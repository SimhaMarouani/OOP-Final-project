#pragma once
#include "GameObjects.h"


class StaticObjects : public GameObjects
{
public:
	StaticObjects();
	StaticObjects(Objects type, sf::Vector2f pos, sf::Vector2f scale);
	StaticObjects(Objects type, b2World* world, sf::Vector2f pos, sf::Vector2f scale);
	StaticObjects(Grounds type, b2World* world, sf::Vector2f pos, sf::Vector2f scale);

	void initIcon(sf::Vector2f pos, sf::Vector2f scale);
	void update();
private:
};