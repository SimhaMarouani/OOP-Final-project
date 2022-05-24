#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Macros.h"

#include "playersInclude/Light.h"
#include "playersInclude/Heavy.h"
#include "playersInclude/Simple.h"
#include "objectsInclude/StaticObjects.h" //Tali: will change to appropriate object header files



class Controller;

class Board 
{
public:
	Board();

	void draw(sf::RenderWindow& window);

//	void createBoard();
	void setActiveDirection(Direction dir);
	void moveActive(float deltaTime);
private:
	//int m_level;
	//will change to static object vector
	sf::RectangleShape m_leftblock;
	sf::RectangleShape m_rightblock;
	
	/*
	Tali: for now i didnt put in vector so
	that we can work on them individually and
	make sure things work
	*/
	Light m_lightPlayer;
	Heavy m_heavyPlayer;
	Simple m_simplePlayer;
};
