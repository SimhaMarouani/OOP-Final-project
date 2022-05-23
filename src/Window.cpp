#include "Controller.h"
#include "Window.h"

Window::Window()
    : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_TITLE, sf::Style::Close | sf::Style::Titlebar)
{
	m_window.setFramerateLimit(60);
	m_menuBackground.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
	m_menuBackground.setTexture(Resources::instance().getBackground(Backgrounds::menu));
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

// add template T = HomePageScreen LevelMenu Game
// in header file:
//template <class T>
//void Window::drawHomePage(T& homePage) { t.draw() }

void Window::drawHomePage(HomePageScreen& homePage)
{
	m_window.draw(m_menuBackground);
	homePage.draw(m_window);
}

void Window::drawLevelMenuPage()
{
}

void Window::drawGame(GameScreen& gameScreen)
{
	gameScreen.draw(m_window);
}

