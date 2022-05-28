#pragma once

#include <iostream>

enum class Page
{
	HomePage = 0,
	LevelMenu,
	Game
};

//buttons in home page = HomePageScreen
enum class HomeButtonType
{
	Start = 0,
	Help,
	Settings,
	Exit,
	None
};

enum class Backgrounds
{
	menu,
	game,
	win,
	lose,
	help
};

enum class Player
{
	Heavy = 0,
	Simple,
	Light
};

enum class Direction
{
	Up,
	Right,
	Left,
	None
};

enum class Objects
{
	Hay
};