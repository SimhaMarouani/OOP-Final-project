#pragma once

#include <iostream>

enum class Page
{
	HomePage = 0,
	LevelMenu,
	Game
};

//buttons in home page = Menu
enum class HomeButtonType
{
	Start = 0,
	Help,
	Settings,
	Exit,
	None
};