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

class Controller
{
public:
	Controller();

	void run();
	
	void startGame(ScreenType page, unsigned int level);
	void updatePage(ScreenType page);
	void exit();
	void changeMusic(ScreenType s) const;
	void updateNumOfLevels();
private:
	void processEvents();
	void update();
	void render();
	void drawCurrPage();

	Window m_window;
	sf::Clock m_timer;
	ScreenType m_currPage;
	
	//=== Screens
	std::vector<std::unique_ptr<Screen>> m_screens;
};
