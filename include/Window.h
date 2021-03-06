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

    bool isOpen() const;
    bool pollEvent(sf::Event& event);
    void close();
    void clear(const sf::Color& color = sf::Color::Color::White);
    void display();
    sf::Vector2f mapPixelToCoords(const sf::Vector2i &vec) const;

    template <class T>
    void drawScreen(T* t) { t->draw(m_window); }


private:
    sf::RenderWindow m_window;
};