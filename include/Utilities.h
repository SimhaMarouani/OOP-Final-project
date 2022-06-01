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
	menu = 0,
	levelmenu,
	game,
	win,
	lose,
	help,
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

enum class LevelState
{
	Lock = 0,
	Unlock
};

enum class LevelActions 
{ 
	Retry = 0,
	Pause,
	None = -1
};