#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <string>
#include <sstream>

//#include "GameObjects.h"
//class GameObjects;
#include "playersInclude/Heavy.h"
#include "playersInclude/Simple.h"
#include "playersInclude/Light.h"
#include "objectsInclude/StaticObjects.h"
#include "objectsInclude/Box.h"



class PlayerFactory {
public:
	using pFnc = std::unique_ptr<Players>(*)();
	static std::unique_ptr<Players> create(const std::string& name);
	static void registerit(const std::string& name, pFnc);
private:
	static auto& getMap() {
		static std::map<std::string, pFnc> map;
		return map;
	}
};

class ObjectFactory {
public:
	using pFnc = std::unique_ptr<StaticObjects>(*)();
	static std::unique_ptr<StaticObjects> create(const std::string& name);
	static void registerit(const std::string& name, pFnc);
private:
	static auto& getObjMap() {
		static std::map<std::string, pFnc> objMap;
		return objMap;
	}
};

/*
Tali:

Michal showed a few methods of implementing this: the last one (which she says is the best) cannot
be done without magaliut(read in hebrew) of files. Maybe there is a way but i will have to ask
someone cause the internet didnt help.

Because of this: I used her second to last method that she shows in Factory3.cpp example

Problem: (with last method): any where you create unique_ptr, the entire class must be recognized
for constructing and deconstructing purposes (include of whole file)
*/