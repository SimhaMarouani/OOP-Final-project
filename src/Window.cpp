#include "Controller.h"
#include "Window.h"

Window::Window()
    : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_TITLE, sf::Style::Close | sf::Style::Titlebar)
	//: m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, sf::VideoMode::getDesktopMode().bitsPerPixel), GAME_TITLE,sf::Style::Resize| sf::Style::Close | sf::Style::Titlebar)
{
	m_window.setFramerateLimit(70);
	auto desktop = sf::VideoMode::getDesktopMode();
	m_window.setPosition(sf::Vector2i(
		desktop.width / 2 - m_window.getSize().x / 2,
		desktop.height / 2 - m_window.getSize().y / 2
	));
	sf::Image image = (*Resources::instance().getGameIcon());
	m_window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
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

//TODO: delete style and settings if not in use
void Window::create(sf::VideoMode mode, const sf::String& title, sf::Uint32 style, const sf::ContextSettings& settings)
{
	m_window.create(mode, title);
}

