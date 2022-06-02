#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Macros.h"

#include "playersInclude/Light.h"
#include "playersInclude/Heavy.h"
#include "playersInclude/Simple.h"


class Board 
{
public:
	Board();

	void draw(sf::RenderWindow& window);
//	void createBoard();

private:
	//int m_level;

	

	Light m_lightPlayer;
	Heavy m_heavyPlayer;
	Simple m_simplePlayer;
};
