#pragma once

#include <iostream>

void calcTime(int&, int&);

enum class ScreenType
{
	HomePage = 0,
	LevelMenu,
	Game
};

enum class HomeButtonType
{
	Start = 0,
	Help,
	Settings,
	Exit,
	None
};

enum class EndLevelButtonType
{
	Retry = 0,
	Menu,
	Next
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
	Rafter,
	Switch,
	Billboard,
	SwitchOn
};

enum class Grounds
{
	Left_l1,
	Right_l1,
	l2,
	Left_l3,
	Right_l3,
	l3,
	l4,
	Door
};

enum class LevelState
{
	Lock = 0,
	Unlock
};

enum class LevelActions 
{ 
	Retry = 0,
	Pause = 1,
    Win,
    Lose,
	None = -1
};

enum class SoundStatus
{
	AudioOn = 0,
	AudioOff,
	MusicOn,
	MusicOff
};
