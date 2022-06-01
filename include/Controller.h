#pragma once


#include "Window.h"
#include "Screens/HomePageScreen.h"
#include "Screens/LevelMenuScreen.h"
#include "Screens/GameScreen.h"

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
	
	void startGame(Page page, int level);
	void updatePage(Page page);
	void exit();

private:
	void processEvents();
	void update();
	void render();
	void drawCurrPage();

	void handleKeyboardPress();
	

	Window m_window;
	sf::Clock m_timer;
	Page m_currPage;
	
	//=== Screens
	HomePageScreen m_homePageScreen;
	LevelMenuScreen m_levelMenuScreen;
	GameScreen m_gameScreen;


};
