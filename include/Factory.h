#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <string>
#include <sstream>


#include "playersInclude/Heavy.h"
#include "playersInclude/Simple.h"
#include "playersInclude/Light.h"

#include "objectsInclude/Box.h"
#include "objectsInclude/Switch.h"
#include "objectsInclude/Billboard.h"
#include "objectsInclude/Door.h"
#include "objectsInclude/Floor.h"

class ObjectFactory 
{
public:
	using pFnc = std::unique_ptr<StaticObjects>(*)(sf::Vector2f pos, b2World* world, sf::Vector2f scale);
	static std::unique_ptr<StaticObjects> create(const std::string& name, sf::Vector2f pos, b2World* world, sf::Vector2f scale);
	static void registerit(const std::string& name, pFnc);

private:
	static auto& getObjMap() {
		static std::map<std::string, pFnc> objMap;
		return objMap;
	}
};
