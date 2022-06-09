#include "WinScreen.h"


WinScreen::WinScreen()
: m_background(sf::Vector2f(END_WIDTH, END_HEIGHT)),
  m_menuBtn(*Resources::instance().getMenuBtn()),
  m_nextLevelBtn(*Resources::instance().getNextLevelBtn()),
  m_retryBtn(*Resources::instance().getRetryBtn())
{
    m_background.setTexture(Resources::instance().getWinBackground());
    m_background.setPosition(sf::Vector2f((WINDOW_WIDTH - END_WIDTH) / 2, (WINDOW_HEIGHT - END_HEIGHT) / 3));

    createBtns();
}

void WinScreen::createBtns()
{
    m_retryBtn.setSize(sf::Vector2f(150,70));
    m_menuBtn.setSize(sf::Vector2f(150,70));
    m_nextLevelBtn.setSize(sf::Vector2f(150,70));

    m_retryBtn.setPosition(sf::Vector2f(570, (WINDOW_HEIGHT - END_HEIGHT*1.5)));
    m_menuBtn.setPosition(sf::Vector2f(720, (WINDOW_HEIGHT - END_HEIGHT*1.5) ));
    m_nextLevelBtn.setPosition(sf::Vector2f(870,(WINDOW_HEIGHT - END_HEIGHT*1.5) ));
}

void WinScreen::draw(sf::RenderWindow &window)
{
    window.draw(m_background);
    m_retryBtn.draw(window);
    m_menuBtn.draw(window);
    m_nextLevelBtn.draw(window);
}

bool WinScreen::isContainRetry(sf::Event e) const
{
    m_retryBtn.isContain(e);
}

bool WinScreen::isContainMenu(sf::Event e) const
{
    m_menuBtn.isContain(e);
}

bool WinScreen::isContainNext(sf::Event e) const
{
    m_nextLevelBtn.isContain(e);
}