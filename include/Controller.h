#pragma once

#include "box2d/box2d.h"

#include "Window.h"
#include "Screens/HomePageScreen.h"
#include "Screens/LevelMenuScreen.h"
#include "Screens/GameScreen.h"

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
	
	void startGame(Page page, int level);
	void updatePage(Page page);
	void exit();

	void resetTimer();


private:
	void processEvents();
	void processEventsHome(sf::Event event);
	void processEventsLevelMenu(sf::Event event);
	void processEventsGame(sf::Event event);
	void update();
	void render();
	void drawCurrPage();

	void handleKeyboardPress();
	
	void setWorld();
	float m_timeStep = 1.0f / 60.0f;
	int32 m_velocityIterations = 8;
	int32 m_positionIterations = 3;

	int m_currPlayer; //TODO: move to gameScreen
	Window m_window;
	b2BodyDef m_groundBodyDef; // Define the ground body

	sf::Clock m_timer;

	Page m_currPage;
	std::unique_ptr<b2World> m_world;
	//=== Screens
	HomePageScreen m_homePageScreen;
	LevelMenuScreen m_levelMenuScreen;
	GameScreen m_gameScreen;

	//TODO: create levelMenuScreen

};
