#pragma once
#include <SFML/Graphics.hpp>
#include "World.h"
#include "DataDisplay.h"
#include "Utilities.h"

class Controller;
class HomePageScreen;
class LevelMenuScreen;
class GameScreen;

class Window
{
public:
    Window();
    void update();
    bool isOpen();
    bool pollEvent(sf::Event& event);
    void close();
    void clear(sf::Color color = sf::Color::Color::White);
    void display();
    void create(sf::VideoMode mode, const sf::String& title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());
    const sf::View& getView() { return m_window.getView(); }
    void setView(const sf::View &v) {  m_window.setView(v); }
    template <class T>
    void drawScreen(T& t) { t.draw(m_window); }

    /*sf::RenderWindow* PTRW()
    {
        return &m_window;
    }*/

private:
    sf::RenderWindow m_window;
};