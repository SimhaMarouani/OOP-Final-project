#include "Controller.h"


Controller::Controller() 
	: m_window()
{}

void Controller::run()
{
	srand(time(NULL));
	//setGameIcon(window);
	//GameBoard gameBoard(MAX_BLOCK_TILES);

	while (m_window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Controller::processEvents()
{
	m_window.processEvents(*this);
}

void Controller::update()
{
}

void Controller::render()
{
	m_window.render();
}
