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
    void drawHomePage(HomePageScreen &homePage); 
    void drawLevelMenuPage(LevelMenuScreen &levelMenuScreen);
    void drawGame(GameScreen & gameScreen);


    sf::RenderWindow* PTRW()
    {
        return &m_window;
    }
private:
    sf::RenderWindow m_window;
    sf::RectangleShape m_menuBackground;
    //sf::RectangleShape m_winBackground;
    //sf::RectangleShape m_loseBackground;
};