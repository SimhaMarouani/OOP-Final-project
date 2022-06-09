#include "CollisionHandler.h"


//-----------------------------------------------------------------
CollisionHandler::CollisionHandler()
{
    intializeMap();
}

void CollisionHandler::intializeMap()
{
    //Player with object
    m_hitMap[Key(typeid(Light), typeid(Floor))] = &CollisionHandler::sheepStatic;
    m_hitMap[Key(typeid(Simple), typeid(Floor))] = &CollisionHandler::sheepStatic;
    m_hitMap[Key(typeid(Heavy), typeid(Floor))] = &CollisionHandler::sheepStatic;
    m_hitMap[Key(typeid(Light), typeid(Box))] = &CollisionHandler::sheepStatic;
    m_hitMap[Key(typeid(Simple), typeid(Box))] = &CollisionHandler::sheepStatic;
    m_hitMap[Key(typeid(Heavy), typeid(Box))] = &CollisionHandler::sheepStatic;

    //Player with Player
    m_hitMap[Key(typeid(Heavy), typeid(Light))] = &CollisionHandler::sheepPlayer;
    m_hitMap[Key(typeid(Heavy), typeid(Simple))] = &CollisionHandler::sheepPlayer;
    m_hitMap[Key(typeid(Light), typeid(Simple))] = &CollisionHandler::sheepPlayer;
    m_hitMap[Key(typeid(Light), typeid(Heavy))] = &CollisionHandler::sheepPlayer;
    m_hitMap[Key(typeid(Simple), typeid(Light))] = &CollisionHandler::sheepPlayer;
    m_hitMap[Key(typeid(Simple), typeid(Heavy))] = &CollisionHandler::sheepPlayer;

    //Object with Player
    m_hitMap[Key(typeid(Floor), typeid(Light))] = &CollisionHandler::staticSheep;
    m_hitMap[Key(typeid(Floor), typeid(Simple))] = &CollisionHandler::staticSheep;
    m_hitMap[Key(typeid(Floor), typeid(Heavy))] = &CollisionHandler::staticSheep;
    m_hitMap[Key(typeid(Box), typeid(Light))] = &CollisionHandler::staticSheep;
    m_hitMap[Key(typeid(Box), typeid(Simple))] = &CollisionHandler::staticSheep;
    m_hitMap[Key(typeid(Box), typeid(Heavy))] = &CollisionHandler::staticSheep;
}

//PRIMARY COLLISION HANDLER
void CollisionHandler::sheepStatic(GameObjects* sheep, GameObjects* stat, bool footSensor1, bool footSensor2)
{
    Players* sh = static_cast<Players*>(sheep);
    StaticObjects* statObj = static_cast<StaticObjects*>(stat);

    if (!sh || !statObj)
        return;

    if (footSensor1)
        sh->setTouchingFloor(true);
}

void CollisionHandler::sheepPlayer(GameObjects* sheep, GameObjects* player, bool footSensor1, bool footSensor2)
{
    Players* sh1 = static_cast<Players*>(sheep);
    Players* sh2 = static_cast<Players*>(player);

    if (!sh1 || !sh2)
        return;

    if (footSensor1)
        sh1->setTouchingFloor(true);

    if (footSensor2)
        sh2->setTouchingFloor(true);

}


//SECONDARY COLLISION HANDLER
void CollisionHandler::staticSheep(GameObjects* stat, GameObjects* sheep, bool footSensor1, bool footSensor2)
{
    sheepStatic(sheep, stat, footSensor2, footSensor1);
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
    auto hit = m_hitMap.find(Key(typeid(*object1), typeid(*object2)));
    if (hit != m_hitMap.end())
    {
        auto func = hit->second;
        (this->*(func))(object1, object2, footSensor1, footSensor2);
    }
}
