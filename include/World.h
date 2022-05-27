#pragma once
#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"
#include <vector>

#include "Macros.h"
#include "playersInclude/Players.h"
#include "playersInclude/Light.h"
#include "playersInclude/Heavy.h"
#include "playersInclude/Simple.h"
#include "objectsInclude/StaticObjects.h" //Tali: will change to appropriate object header files



#include "DebugDraw.h"

class Controller;

class World 
{
public:
	World();

	void draw(sf::RenderWindow& window);

//	void createBoard();
	void setActiveDirection(Direction dir, Player active);
	void moveActive(float deltaTime, Player active);

	void SetDebugDraw(DebugDraw* d)
	{
		m_box2dWorld.SetDebugDraw(d);
	}


	b2World* getWorld() { return &m_box2dWorld; }

private:

	void initPlayers();
	//int m_level;
	// 
	//will change to static object vector
	sf::RectangleShape m_leftblock;
	sf::RectangleShape m_rightblock;

	b2World m_box2dWorld;
	sf::Sprite m_arrow;

	std::vector<Players> m_players;

	b2Body* groundBody;
	sf::RectangleShape ground;
};
