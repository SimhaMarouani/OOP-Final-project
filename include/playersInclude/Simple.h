#pragma once
#include "Players.h"
//#include "Board.h"

class Simple : public Players
{
public:
	Simple();
	//Simple(sf::Vector2f position/*, Board& board*/);
	Simple(b2World* world);
	//~Simple() = default;



	//void move(float deltaTime);

private:

};