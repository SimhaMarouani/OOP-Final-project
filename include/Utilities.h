#pragma once

#include <iostream>

enum class Screen
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
	Hay,
};

enum class Grounds
{
	Left_l1,
	Right_l1,
	l2,
	Left_l3,
	Right_l3,
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