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

enum class Elements
{
	simplePlayer,
	heavyPlayer,
	lightPlayer,
};
