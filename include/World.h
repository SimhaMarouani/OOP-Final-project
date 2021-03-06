#pragma once
#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"
#include <vector>
#include <fstream>
#include <exception>

#include "Macros.h"
#include "playersInclude/Players.h"
#include "objectsInclude/StaticObjects.h"
#include "objectsInclude/Border.h"
#include "MyContactListener.h"

#include "Factory.h"
#include "DebugDraw.h"

//box2d
const float timeStep = 1.0f / 60.0f;
const int32 velocityIterations = 6, positionIterations = 2;
const b2Vec2 gravity = b2Vec2(0.0f, 10.0f);
const sf::Vector2f initVec = sf::Vector2f(0.f, 0.f);
constexpr int DEFAULT_ENDPOINT = 1400;

class Controller;

class World 
{
public:
	World();
	~World();
	void draw(sf::RenderWindow& window, const Player activePlayer);
	void moveActive(float deltaTime, const Player active);
	void moveArrow(const Player active);

	void SetDebugDraw(DebugDraw* d)
	{
		m_box2dWorld->SetDebugDraw(d);
	}

	void createLevel(const int level);
	b2World* getWorld() { return m_box2dWorld.get(); }

	bool allPlayersReachedEnd()const;
    bool playerLost()const;


private:
    void loadLevel(const int levelNum);
	void createBorders();
	void initPlayers();
	void initSymbols();
	bool isPlayer(const std::string type)const;
	int getIndPlayer(const std::string player)const;


	std::unique_ptr<b2World> m_box2dWorld;
	sf::Sprite m_arrow;
	sf::Sprite m_sign;
	
	std::vector<std::unique_ptr<Players>> m_players;
	std::vector<std::unique_ptr<StaticObjects>> m_objects;
	std::vector<std::unique_ptr<StaticObjects>> m_borders;

	int m_endpoint = DEFAULT_ENDPOINT;
	
	MyContactListener m_contactListener;
};
