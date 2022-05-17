#include "Controller.h"
#include "Window.h"

Window::Window()
    : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_TITLE, sf::Style::Close | sf::Style::Titlebar)
{
}

void Window::update()
{
}

bool Window::isOpen()
{
    return m_window.isOpen();
}

bool Window::pollEvent(sf::Event& event)
{
	return m_window.pollEvent(event);
}

void Window::close()
{
	m_window.close();
}

void Window::clear(sf::Color color)
{
	m_window.clear(color);
}

void Window::display()
{
	m_window.display();
}

void Window::drawHomePage(Menu& homePage)
{
	homePage.draw(m_window);
}

void Window::drawLevelMenuPage()
{
}

void Window::drawGame()
{
}
