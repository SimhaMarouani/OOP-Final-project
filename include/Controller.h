#pragma once
#include <memory>
#include <vector>

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
private:
	void processEvents();
	void processEventsHome(sf::Event event);

	void update();
	void render();
	void drawCurrPage();


private:
	Page m_currPage;
	Menu m_homePage;
	
	//	Board m_board;
	Window m_window;
	DataDisplay m_dataDisplay;
};
