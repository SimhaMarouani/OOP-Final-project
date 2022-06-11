#pragma once
#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"
#include <vector>
#include <fstream>
#include <exception>

#include "Macros.h"
#include "playersInclude/Players.h"
#include "objectsInclude/StaticObjects.h"
#include "MyContactListener.h"

#include "Factory.h"
#include "DebugDraw.h"


class Controller;

class World 
{
public:
	World();
	~World();
	void draw(sf::RenderWindow& window);
	void setActiveDirection(Direction dir, Player active);
	void moveActive(float deltaTime, Player active);
	void moveArrow(Player active);

	void SetDebugDraw(DebugDraw* d)
	{
		m_box2dWorld->SetDebugDraw(d);
	}

	void createLevel(int level);
	b2World* getWorld() { return m_box2dWorld.get(); }

	bool allPlayersReachedEnd();
    bool playerLost();

    void loadLevel(int levelNum);

private:
	void initPlayers();
	void initSymbols();
	bool isPlayer(std::string type)const;
	int getIndPlayer(std::string player)const;


	std::unique_ptr<b2World> m_box2dWorld;
	sf::Sprite m_arrow;
	sf::Sprite m_sign;
	
	std::vector<std::unique_ptr<Players>> m_players;
	std::vector<std::unique_ptr<StaticObjects>> m_objects;

	int m_endpoint = 1400;
	
	MyContactListener contactListener;
};
