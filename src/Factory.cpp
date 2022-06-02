#include "Factory.h"


std::unique_ptr<Players> PlayerFactory::create(const std::string& name) 
{
	static bool initial = true;
	if (initial) {

		registerit("Heavy", []() -> std::unique_ptr<Players> { return std::make_unique<Heavy>(); });
		registerit("Simple", []() -> std::unique_ptr<Players> { return std::make_unique<Simple>(); });
		registerit("Light", []() -> std::unique_ptr<Players> { return std::make_unique<Light>(); });

		initial = false;
	}

	auto it = PlayerFactory::getMap().find(name);
	if (it == PlayerFactory::getMap().end())
		return nullptr;
	return it->second();
}

void PlayerFactory::registerit(const std::string& name, pFnc f) 
{
	PlayerFactory::getMap().emplace(name, f);
}


//=======================================================================
		//STATIC OBJECTS FACTORY
//=======================================================================


std::unique_ptr<StaticObjects> ObjectFactory::create(const std::string& name, sf::Vector2f pos) 
{
	static bool initial = true;
	if (initial) {

		registerit("Hay",	  [](sf::Vector2f pos) -> std::unique_ptr<StaticObjects> { return std::make_unique<Box>(pos); });
		registerit("l_floor", [](sf::Vector2f pos) -> std::unique_ptr<StaticObjects> { return std::make_unique<Floor>(pos, Grounds::Left_l1); });
		registerit("r_floor", [](sf::Vector2f pos) -> std::unique_ptr<StaticObjects> { return std::make_unique<Floor>(pos, Grounds::Right_l1); });
		registerit("floor",	  [](sf::Vector2f pos) -> std::unique_ptr<StaticObjects> { return std::make_unique<Floor>(pos, Grounds::l2); });
		
		initial = false;
	}

	auto it = ObjectFactory::getObjMap().find(name);
	if (it == ObjectFactory::getObjMap().end())
		return nullptr;
	return it->second(pos);
}

void ObjectFactory::registerit(const std::string& name, pFnc f) 
{
	ObjectFactory::getObjMap().emplace(name, f);
}