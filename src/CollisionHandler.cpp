#include "CollisionHandler.h"


//-----------------------------------------------------------------
CollisionHandler::CollisionHandler()
{
    intializeMap();
}

void CollisionHandler::intializeMap()
{
    m_hitMap[Key(typeid(Player), typeid(StaticObjects))] = &CollisionHandler::sheepStatic;
    m_hitMap[Key(typeid(Player), typeid(Player))] = &CollisionHandler::sheepPlayer;
    m_hitMap[Key(typeid(StaticObjects), typeid(Player))] = &CollisionHandler::staticSheep;
    m_hitMap[Key(typeid(Player), typeid(Player))] = &CollisionHandler::playerSheep;
}

//PRIMARY COLLISION HANDLER
void CollisionHandler::sheepStatic(GameObjects* sheep, GameObjects* stat)
{
    Players* sh = static_cast<Players*>(sheep);
    StaticObjects* statObj = static_cast<StaticObjects*>(stat);

    if (!sh || !statObj)
        return;


    //else deal with it
}

void CollisionHandler::sheepPlayer(GameObjects* sheep, GameObjects* player)
{
}


//SECONDARY COLLISION HANDLER
void CollisionHandler::staticSheep(GameObjects* stat, GameObjects* sheep)
{
    sheepStatic(sheep, stat);
}

void CollisionHandler::playerSheep(GameObjects* player, GameObjects* sheep)
{
    sheepPlayer(sheep, player);
}

CollisionHandler::~CollisionHandler()
{
}

CollisionHandler& CollisionHandler::instance()
{
	static CollisionHandler inst;
	return inst;
}

void CollisionHandler::processCollision(GameObjects* object1, GameObjects* object2 /*,bool foot1, bool foot2*/)
{
    auto hit = m_hitMap.find(Key(typeid(*object1), typeid(*object2)));
    if (hit != m_hitMap.end())
    {
        auto func = hit->second;
        (this->*(func))(object1, object2/*, foot1, foot2*/);
    }
}
