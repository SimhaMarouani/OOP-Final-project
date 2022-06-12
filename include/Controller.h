#pragma once


#include "Window.h"
#include "Screens/HomePageScreen.h"
#include "Screens/LevelMenuScreen.h"
#include "Screens/GameScreen.h"
#include "Settings.h"

#include "Utilities.h"
#include "Macros.h"

#include <memory>
#include <vector>
#include <typeinfo>

//class GameScreen;

class Controller
{
public:
	Controller();

	void run();
	
	void startGame(Screen page, int level);
	void updatePage(Screen page);
	void exit();
	void changeMusic(Screen s);
	void updateNumOfLevels();
private:
	void processEvents();
	void update();
	void render();
	void drawCurrPage();

	void handleKeyboardPress();

	Window m_window;
	sf::Clock m_timer;
	Screen m_currPage;
	
	//=== Screens
	HomePageScreen m_homePageScreen;
	LevelMenuScreen m_levelMenuScreen;
	GameScreen m_gameScreen;
};
