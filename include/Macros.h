#pragma once
#include <SFML/Graphics.hpp>
#include <string>

//grapics
const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 900;

const int DATA_DISPLAY_WIDTH = 1600; //Noga same as WINDOW_WIDTH maybe we can save only one of them?
const int DATA_DISPLAY_HEIGHT = 150;

const int SETTINGS_WIDTH = WINDOW_WIDTH * 0.4;
const int SETTINGS_HEIGHT = WINDOW_HEIGHT * 0.6;

const int HELP_WIDTH = WINDOW_WIDTH - (WINDOW_WIDTH / 8);
const int HELP_HEIGHT = WINDOW_HEIGHT - (WINDOW_HEIGHT / 8);

const int CHAR_SIZE = 40;

// Level Menu 
const int LEVEL_MENU_COLS = 5;
const float LEVEL_MENU_BTN_SIZE = 220.f;

// DataDisplay
const float PLAYER_FACE_SIZE = 100.f;

//Game title
const std::string GAME_TITLE = "Home Sheep Home";

const sf::Vector2f HOME_BTN_SIZE(350, 150);

//players
const int NUM_OF_PLAYERS = 3;
const int NUM_OF_BG_TEXTURES = 3;
const float BASE_SPEED = 130.0;
const std::string PLAYERS[NUM_OF_PLAYERS] = { "Heavy", "Simple", "Light" };

//objects
const int NUM_OF_OBJS = 2;
const int NUM_OF_GROUNDS = 5;


