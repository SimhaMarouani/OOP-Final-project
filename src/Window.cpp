#include "Controller.h"
#include "Window.h"

Window::Window()
    : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Ice Adventures", sf::Style::Close | sf::Style::Titlebar)
{
}

void Window::processEvents(Controller& controller)//, Board& board)
{
	if (auto event = sf::Event{}; m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();

		/*switch (m_currPage)
		{
		case Page::GameBoard:
			gameBoardProcesEvents(event, window, gameBoard);
			break;
		case Page::UserWin:
		case Page::UserLose:
		default:
			emmptyPageProcessEvents(event);
			break;
		}*/
	}
}

void Window::update()
{
}

void Window::render()
{
	m_window.clear(sf::Color(224, 235, 229));
	//drawCurrPage(window, gameBoard);
	m_window.display();
}

bool Window::isOpen()
{
    return m_window.isOpen();
}
