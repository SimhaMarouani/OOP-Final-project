#pragma once
#include "Players.h"


class Heavy : public Players
{
public:
	Heavy(b2World* world);
private:
	//static bool m_registerit;

};
//bool Heavy::m_registerit = PlayerFactory::registerit("Heavy", []()-> std::unique_ptr<Players> {return std::make_unique<Heavy>(); });


