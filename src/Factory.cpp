#include "Factory.h"


//=======================================================================
		//STATIC OBJECTS FACTORY
//=======================================================================


std::unique_ptr<StaticObjects> ObjectFactory::create(const std::string& name, sf::Vector2f pos, b2World* world)
{
	static bool initial = true;
	if (initial) {

		registerit("Hay",	  [](sf::Vector2f pos, b2World* world) -> std::unique_ptr<StaticObjects> { return std::make_unique<Box>(pos, world); });
		registerit("Rafter",  [](sf::Vector2f pos, b2World* world) -> std::unique_ptr<StaticObjects> { return std::make_unique<Rafter>(pos, world); });
		registerit("l_floor", [](sf::Vector2f pos, b2World* world) -> std::unique_ptr<StaticObjects> { return std::make_unique<Floor>(pos, Grounds::Left_l1, world); });
		registerit("r_floor", [](sf::Vector2f pos, b2World* world) -> std::unique_ptr<StaticObjects> { return std::make_unique<Floor>(pos, Grounds::Right_l1, world); });
		registerit("floor",	  [](sf::Vector2f pos, b2World* world) -> std::unique_ptr<StaticObjects> { return std::make_unique<Floor>(pos, Grounds::l2, world); });
		
		initial = false;
	}

	auto it = ObjectFactory::getObjMap().find(name);
	if (it == ObjectFactory::getObjMap().end())
		return nullptr;
	return it->second(pos, world);
}

void ObjectFactory::registerit(const std::string& name, pFnc f) 
{
	ObjectFactory::getObjMap().emplace(name, f);
}