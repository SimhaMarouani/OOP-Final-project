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
    m_hitMap[Key(typeid(Light), typeid(Rafter))] = &CollisionHandler::sheepStatic;
    m_hitMap[Key(typeid(Simple), typeid(Rafter))] = &CollisionHandler::sheepStatic;
    m_hitMap[Key(typeid(Heavy), typeid(Rafter))] = &CollisionHandler::sheepStatic;
    m_hitMap[Key(typeid(Light), typeid(Switch))] = &CollisionHandler::sheepStatic;
    m_hitMap[Key(typeid(Simple), typeid(Switch))] = &CollisionHandler::sheepStatic;
    m_hitMap[Key(typeid(Heavy), typeid(Switch))] = &CollisionHandler::sheepStatic;

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
    m_hitMap[Key(typeid(Rafter), typeid(Light))] = &CollisionHandler::staticSheep;
    m_hitMap[Key(typeid(Rafter), typeid(Simple))] = &CollisionHandler::staticSheep;
    m_hitMap[Key(typeid(Rafter), typeid(Heavy))] = &CollisionHandler::staticSheep;
    m_hitMap[Key(typeid(Switch), typeid(Light))] = &CollisionHandler::staticSheep;
    m_hitMap[Key(typeid(Switch), typeid(Simple))] = &CollisionHandler::staticSheep;
    m_hitMap[Key(typeid(Switch), typeid(Heavy))] = &CollisionHandler::staticSheep;

    //Object with Object
    m_hitMap[Key(typeid(Switch), typeid(Box))] = &CollisionHandler::switchStatic;
    m_hitMap[Key(typeid(Switch), typeid(Rafter))] = &CollisionHandler::switchStatic;
    m_hitMap[Key(typeid(Box), typeid(Switch))] = &CollisionHandler::staticSwitch;
    m_hitMap[Key(typeid(Rafter), typeid(Switch))] = &CollisionHandler::staticSwitch;
}


//PRIMARY COLLISION HANDLER
void CollisionHandler::sheepStatic(GameObjects* sheep, GameObjects* stat, bool footSensor1, bool footSensor2, bool contact)
{
    Players* sh = static_cast<Players*>(sheep);
    StaticObjects* statObj = static_cast<StaticObjects*>(stat);

    if (!sh || !statObj)
        return;

    if (auto sw = dynamic_cast<Switch*>(stat))
    {
        sw->setPressed(contact);
    }
    else if (footSensor1)
        sh->setTouchingFloor(contact);
}

void CollisionHandler::sheepPlayer(GameObjects* sheep, GameObjects* player, bool footSensor1, bool footSensor2, bool contact)
{
    Players* sh1 = static_cast<Players*>(sheep);
    Players* sh2 = static_cast<Players*>(player);

    if (!sh1 || !sh2)
        return;

    if (footSensor1)
        sh1->setTouchingFloor(contact);

    if (footSensor2)
        sh2->setTouchingFloor(contact);

}

void CollisionHandler::switchStatic(GameObjects* swit, GameObjects* stat, bool footSensor1, bool footSensor2, bool contact)
{
    Switch* sw = static_cast<Switch*>(swit);
    StaticObjects* statObj = static_cast<StaticObjects*>(stat);

    if (!sw || !statObj)
        return;

    if (sw)
    {
        sw->setPressed(contact);
    }
}

//SECONDARY COLLISION HANDLER
void CollisionHandler::staticSheep(GameObjects* stat, GameObjects* sheep, bool footSensor1, bool footSensor2, bool contact)
{
    sheepStatic(sheep, stat, footSensor2, footSensor1, contact);
}

void CollisionHandler::staticSwitch(GameObjects* stat, GameObjects* swit, bool footSensor1, bool footSensor2, bool contact)
{
    switchStatic(swit, stat, footSensor2, footSensor1, contact);
}

CollisionHandler::~CollisionHandler()
{
}

CollisionHandler& CollisionHandler::instance()
{
	static CollisionHandler inst;
	return inst;
}

void CollisionHandler::processCollision(GameObjects* object1, GameObjects* object2 ,bool footSensor1, bool footSensor2, bool contact)
{
    //std::cout << typeid(*object1).name() << " " << typeid(*object2).name() << std::endl;
    auto hit = m_hitMap.find(Key(typeid(*object1), typeid(*object2)));
    if (hit != m_hitMap.end())
    {
        auto func = hit->second;
        (this->*(func))(object1, object2, footSensor1, footSensor2, contact);
    }
}
