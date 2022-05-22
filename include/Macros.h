#pragma once
#include <SFML/Graphics.hpp>
#include <string>

//grapics
const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 900;

const int DATA_DISPLAY_WIDTH = 1600;
const int DATA_DISPLAY_HEIGHT = 150;

const int CHAR_SIZE = 40;

//Game title
const std::string GAME_TITLE = "Ice Adventures";

const sf::Vector2f HOME_BTN_SIZE(300, 100);

//players
const int NUM_OF_PLAYERS = 3;
const int NUM_OF_TEXTURES = 1;

enum class Player
{
	PolarBear,
	Penguin,
	Deer
};