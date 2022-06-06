#pragma once
#include "GameObjects.h"
#include "playersInclude/Players.h"
#include "objectsInclude/StaticObjects.h"


#include <iostream>
#include <unordered_map>
#include <string>
#include <typeinfo>
#include <typeindex>

//Both structs needed for unordered map:
struct PairKeysHash
{
	template<class T>
	size_t operator()(const std::pair<T, T>& p)const
	{
		return std::hash<T>{}(p.first) ^ std::hash<T>{}(p.second);
	}
};

struct KeyEqual
{
	template<class T>
	bool operator()(const std::pair<T, T>& lKey, const std::pair<T, T>& rKey)const
	{
		return lKey.first == rKey.first && lKey.second == rKey.second;
	}
};


class CollisionHandler
{
public:
	using HitFunctionPtr = void (CollisionHandler::*)(GameObjects*, GameObjects*);
	using Key = std::pair<std::type_index, std::type_index>;
	using HitMap = std::unordered_map<Key, HitFunctionPtr, PairKeysHash, KeyEqual>;

	~CollisionHandler();

	//Access data
	static CollisionHandler& instance();

	void processCollision(GameObjects* object1, GameObjects* object2);
private:
	std::unordered_map<Key, HitFunctionPtr, PairKeysHash, KeyEqual> m_hitMap;

	CollisionHandler();
	CollisionHandler(const CollisionHandler&) = default;
	CollisionHandler& operator=(const CollisionHandler&) = default;

	void intializeMap();

	//handle collisions functions

	//Primary collision handler
	void sheepStatic(GameObjects* sheep, GameObjects* stat);
	void sheepPlayer(GameObjects* sheep, GameObjects* player);
	//Secondary collision handler
	void staticSheep(GameObjects* stat, GameObjects* sheep);
	void playerSheep(GameObjects* player, GameObjects* sheep);
	



};
