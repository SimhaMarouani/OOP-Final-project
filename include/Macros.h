#pragma once
#include <SFML/Graphics.hpp>
#include <string>

//grapics
constexpr int WINDOW_WIDTH = 1600;
constexpr int WINDOW_HEIGHT = 900;

constexpr int DATA_DISPLAY_WIDTH = 1600; //Noga same as WINDOW_WIDTH maybe we can save only one of them?
constexpr int DATA_DISPLAY_HEIGHT = 150;

constexpr int SETTINGS_WIDTH = WINDOW_WIDTH * 0.4;
constexpr int SETTINGS_HEIGHT = WINDOW_HEIGHT * 0.6;

constexpr int END_WIDTH = WINDOW_WIDTH * 0.4;
constexpr int END_HEIGHT = WINDOW_HEIGHT * 0.4;

constexpr int HELP_WIDTH = WINDOW_WIDTH - (WINDOW_WIDTH / 8);
constexpr int HELP_HEIGHT = WINDOW_HEIGHT - (WINDOW_HEIGHT / 8);

constexpr int CHAR_SIZE = 40;

// Level Menu 
constexpr int LEVEL_MENU_COLS = 4;
constexpr float LEVEL_MENU_BTN_SIZE = 220.f;
constexpr int NUM_OF_LEVELS = 5;

// DataDisplay
constexpr float PLAYER_FACE_SIZE = 100.f;

//Game title
const std::string GAME_TITLE = "Home Sheep Home";

const std::string HIGH_SCORE_FILE_NAME = "high_score.txt";

const sf::Vector2f HOME_BTN_SIZE(350, 150);
const sf::Vector2f HOVER_HOME_BTN_SIZE(370, 170);

//players
constexpr int NUM_OF_PLAYERS = 3;
constexpr int NUM_OF_BG_TEXTURES = 3;
constexpr float BASE_SPEED = 130.0;
constexpr std::string_view PLAYERS[NUM_OF_PLAYERS] = { "Heavy", "Simple", "Light" };

//objects
constexpr int NUM_OF_OBJS = 5;
constexpr int NUM_OF_GROUNDS = 8;


// animation data:
constexpr std::pair<int, int> lightAnimationRow[4] =
{
	{ 6, 12 }, //jump 
	{ 2, 8 }, //walk
	{ 2, 8 }, //walk
	{ 1, 5 } //stand
};

constexpr std::pair<int, int> simpleAnimationRow[4] =
{
	{ 6, 7 }, //jump
	{ 4, 8 }, //walk
	{ 4, 8 }, //walk
	{ 1, 15 } //stand
};

constexpr std::pair<int, int> heavyAnimationRow[4] =
{
	{ 4, 7 }, //jump
	{ 2, 8 }, //walk
	{ 2, 8 }, //walk
	{ 1, 5 } //stand
};

//std::vector<std::pair<Direction, int>> simpleAnimationCount =
//{
//	{Direction::Up, 7},
//	{Direction::Right, 8 },
//	{Direction::None , 15}
//}