#include "Factory.h"


//=======================================================================
		//STATIC OBJECTS FACTORY
//=======================================================================


std::unique_ptr<StaticObjects> ObjectFactory::create(const std::string& name, sf::Vector2f pos, b2World* world, sf::Vector2f scale)
{
	static bool initial = true;
	if (initial) {

		registerit("Hay",	  [](sf::Vector2f pos, b2World* world, sf::Vector2f scale) -> std::unique_ptr<StaticObjects> { return std::make_unique<Box>(pos, world, scale); });
		registerit("Rafter",  [](sf::Vector2f pos, b2World* world, sf::Vector2f scale) -> std::unique_ptr<StaticObjects> { return std::make_unique<Rafter>(pos, world, scale); });
		registerit("l_floor", [](sf::Vector2f pos, b2World* world, sf::Vector2f scale) -> std::unique_ptr<StaticObjects> { return std::make_unique<Floor>(pos, Grounds::Left_l1, world, scale); });
		registerit("r_floor", [](sf::Vector2f pos, b2World* world, sf::Vector2f scale) -> std::unique_ptr<StaticObjects> { return std::make_unique<Floor>(pos, Grounds::Right_l1, world, scale); });
		registerit("floor",	  [](sf::Vector2f pos, b2World* world, sf::Vector2f scale) -> std::unique_ptr<StaticObjects> { return std::make_unique<Floor>(pos, Grounds::l2, world, scale); });
		registerit("right_floor_L3",[](sf::Vector2f pos, b2World* world, sf::Vector2f scale) -> std::unique_ptr<StaticObjects> { return std::make_unique<Floor>(pos, Grounds::Right_l3, world, scale); });
		
		initial = false;
	}

	auto it = ObjectFactory::getObjMap().find(name);
	if (it == ObjectFactory::getObjMap().end())
		return nullptr;
	return it->second(pos, world, scale);
}

void ObjectFactory::registerit(const std::string& name, pFnc f) 
{
	ObjectFactory::getObjMap().emplace(name, f);
}