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
	/*
	Tali: for now i didnt put in vector so
	that we can work on them individually and
	make sure things work
	*/
	std::vector<Players> m_players;
	/*Light m_lightPlayer;
	Heavy m_heavyPlayer;
	Simple m_simplePlayer;*/



	b2Body* groundBody;
	sf::RectangleShape ground;
};
