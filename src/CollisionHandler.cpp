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
void CollisionHandler::sheepStatic(GameObjects* sheep, GameObjects* stat, bool footSensor1, bool footSensor2)
{
    Players* sh = static_cast<Players*>(sheep);
    StaticObjects* statObj = static_cast<StaticObjects*>(stat);

    if (!sh || !statObj)
        return;

    if (footSensor1 || footSensor2)
        std::cout << "footsensor yall\n";
    //else deal with it
}

void CollisionHandler::sheepPlayer(GameObjects* sheep, GameObjects* player, bool footSensor1, bool footSensor2)
{
    Players* sh1 = static_cast<Players*>(sheep);
    Players* sh2 = static_cast<Players*>(player);

    if (!sh1 || !sh2)
        return;

    if (footSensor1 || footSensor2)
        std::cout << "footsensor yall\n";
}


//SECONDARY COLLISION HANDLER
void CollisionHandler::staticSheep(GameObjects* stat, GameObjects* sheep, bool footSensor1, bool footSensor2)
{
    sheepStatic(sheep, stat, footSensor2, footSensor1);
}

void CollisionHandler::playerSheep(GameObjects* player, GameObjects* sheep, bool footSensor1, bool footSensor2)
{
    sheepPlayer(sheep, player, footSensor2, footSensor1);
}

CollisionHandler::~CollisionHandler()
{
}

CollisionHandler& CollisionHandler::instance()
{
	static CollisionHandler inst;
	return inst;
}

void CollisionHandler::processCollision(GameObjects* object1, GameObjects* object2 ,bool footSensor1, bool footSensor2)
{
    if (footSensor1)
        std::cout << "foot sensor yes bro u know\n";
    auto hit = m_hitMap.find(Key(typeid(*object1), typeid(*object2)));
    if (hit != m_hitMap.end())
    {
        auto func = hit->second;
        (this->*(func))(object1, object2, footSensor1, footSensor2);
    }
}
