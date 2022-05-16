#pragma once
#include <memory>
#include <vector>

#include "Board.h"
#include "Window.h"
#include "DataDisplay.h"

#include "Macros.h"


class Controller
{
public:
	Controller();

	void run();
	
private:
//	Board m_board;
	Window m_window;
	DataDisplay m_dataDisplay;
};
