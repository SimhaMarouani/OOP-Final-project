#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <string>
#include "Button.h"
#include "Resources.h"
#include "Utilities.h"
//#include "Controller.h"


class WinScreen{
public:
    WinScreen();
    virtual ~WinScreen() = default;

    void draw(sf::RenderWindow& window);

    void handleClick(sf::Event event);

    bool isContainRetry(sf::Event e) const;
    bool isContainMenu(sf::Event e) const;
    bool isContainNext(sf::Event e) const;
    //bool isContainHome(sf::Event e) const;

private:
    void createBtns();

    sf::RectangleShape m_background;

    Button m_retryBtn;
    Button m_nextLevelBtn;
    Button m_menuBtn;
};
