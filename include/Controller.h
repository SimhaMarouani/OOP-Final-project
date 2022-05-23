#pragma once

#include "box2d/box2d.h"

#include "Board.h"
#include "Window.h"
#include "Screens/HomePageScreen.h"
#include "DataDisplay.h"

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
	
	void updatePage(Page page);
	void exit();

	void createPlayersVec(/*char type, sf::Vector2f position, sf::Vector2f size*/);


private:
	void processEvents();
	void processEventsHome(sf::Event event);
	void processEventsGame(sf::Event event);

	void update();
	void render();
	void drawCurrPage();
	sf::Keyboard::Key handleKey();

private:
	int m_currPlayer; //TODO: move to gameScreen
	Window m_window;
	b2BodyDef m_groundBodyDef; // Define the ground body

	sf::Clock m_timer;

	Page m_currPage;

	//=== Screens
	HomePageScreen m_homePage;
	//Noga: add gameScreen
	Board m_board;
	DataDisplay m_dataDisplay;

	//TODO: create levelMenuScreen

	//TODO: move to gameScreen
	//std::unique_ptr<Players> m_playersVec[3];

};
