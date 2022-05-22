#pragma once
#include <memory>
#include <vector>

#include "box2d/box2d.h"

#include "Board.h"
#include "Window.h"
#include "Menu.h"
#include "DataDisplay.h"

#include "Utilities.h"
#include "Macros.h"


class Controller
{
public:
	Controller();

	void run();
	
	void updatePage(Page page);
	void exit();

	void createPlayersVec(char type, sf::Vector2f position, sf::Vector2f size);


private:
	void processEvents();
	void processEventsHome(sf::Event event);

	void update();
	void render();
	void drawCurrPage();


private:
	sf::Keyboard::Key handleKey();


	Page m_currPage;
	Menu m_homePage;
	
	Board m_board;
	Window m_window;
	DataDisplay m_dataDisplay;

	b2BodyDef m_groundBodyDef;		// Define the ground body

	std::unique_ptr<Players> m_playersVec[3];

	int m_currPlayer;
};
