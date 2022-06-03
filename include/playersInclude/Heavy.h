#pragma once
#include "Players.h"
//#include "Board.h"

class Heavy : public Players
{
public:
	Heavy();
	//Heavy(sf::Vector2f position/*, Board& board*/);
	Heavy(b2World* world);


	//void move(float deltaTime);

private:
	//static bool m_registerit;

};
//bool Heavy::m_registerit = PlayerFactory::registerit("Heavy", []()-> std::unique_ptr<Players> {return std::make_unique<Heavy>(); });


