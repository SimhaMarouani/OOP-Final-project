#pragma once
#include "Players.h"
//#include "Board.h"


class Light : public Players
{
public:
	Light();
	//Light(sf::Vector2f position/*, Board& board*/);
	Light(b2World* world);


	//void move(float deltaTime);

private:

};