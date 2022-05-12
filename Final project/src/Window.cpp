#include "Controller.h"
#include "Window.h"

Window::Window()
    : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Ice Adventures", sf::Style::Close | sf::Style::Titlebar)
{
}
