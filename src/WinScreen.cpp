#include "WinScreen.h"


WinScreen::WinScreen()
: m_background(sf::Vector2f(END_WIDTH, END_HEIGHT)),
  m_retryBtn(*Resources::instance().getRetryBtn()),
  m_menuBtn(*Resources::instance().getMenuBtn()),
  m_nextLevelBtn(*Resources::instance().getNextLevelBtn())
{
    m_background.setTexture(Resources::instance().getWinBackground());
    m_background.setPosition(sf::Vector2f((WINDOW_WIDTH - END_WIDTH) / 2, (WINDOW_HEIGHT - END_HEIGHT) / 3));

    createBtns();
    createText();
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

    window.draw(m_text);
    window.draw(m_timeText);
}

bool WinScreen::isContainRetry(sf::Event e) const
{
    return m_retryBtn.isContain(e);
}

bool WinScreen::isContainMenu(sf::Event e) const
{
    return m_menuBtn.isContain(e);
}

bool WinScreen::isContainNext(sf::Event e) const
{
    return m_nextLevelBtn.isContain(e);
}

void WinScreen::createText()
{
    m_text.setFont(*Resources::instance().getFont());
    m_text.setCharacterSize(CHAR_SIZE);
    m_text.setPosition(580, 300);
    m_text.setColor(sf::Color::Black);
    m_text.setString("Great! you won this level");

    m_timeText.setFont(*Resources::instance().getFont());
    m_timeText.setCharacterSize(CHAR_SIZE);
    m_timeText.setPosition(660, 370);
    m_timeText.setColor(sf::Color::Black);
    m_timeText.setString("Time: ");     //simha: need to read the time from data display

}