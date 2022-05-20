#pragma once
#include <SFML/Graphics.hpp>
#include <string>

//grapics
const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 900;

//Game title
const std::string GAME_TITLE = "Ice Adventures";

const sf::Vector2f HOME_BTN_SIZE(300, 100);

//players
const int NUM_OF_PLAYERS = 3;

enum class Player
{
	PolarBear,
	Penguin,
	Deer
};