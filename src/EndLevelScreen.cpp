#include "EndLevelScreen.h"

EndLevelScreen::EndLevelScreen()
: m_background(sf::Vector2f(END_WIDTH, END_HEIGHT)),
  m_retryBtn(*Resources::instance().getRetryBtn()),
  m_menuBtn(*Resources::instance().getMenuBtn()),
  m_nextLevelBtn(*Resources::instance().getNextLevelBtn()),
  m_winSound(Resources::instance().getAudioWin()),
  m_loseSound(Resources::instance().getAudioLose()),
  m_soundCounter(0)
{
    m_background.setTexture(Resources::instance().getWinBackground());
    m_background.setPosition(sf::Vector2f((WINDOW_WIDTH - END_WIDTH) / 2, (WINDOW_HEIGHT - END_HEIGHT) / 3));
    createText();
    createBtns();
}

void EndLevelScreen::createBtns()
{
    m_retryBtn.setSize(sf::Vector2f(150,70));
    m_menuBtn.setSize(sf::Vector2f(150,70));
    m_nextLevelBtn.setSize(sf::Vector2f(150,70));

    m_retryBtn.setPosition(sf::Vector2f(570, (WINDOW_HEIGHT - END_HEIGHT)));
    m_menuBtn.setPosition(sf::Vector2f(720, (WINDOW_HEIGHT - END_HEIGHT) ));
    m_nextLevelBtn.setPosition(sf::Vector2f(870,(WINDOW_HEIGHT - END_HEIGHT) ));
}

void EndLevelScreen::draw(sf::RenderWindow &window, bool status, int levelNum, int time)
{
    playSound(status);

    window.draw(m_background);

    m_retryBtn.draw(window);
    m_menuBtn.draw(window);

    if (status && levelNum < NUM_OF_LEVELS)
    {
        m_nextLevelBtn.draw(window);

        window.draw(m_winText);
        window.draw(m_timeText);

        if(time <= HighScore::instance().getLevelScore(levelNum))
        {
            m_newScoreText.setString("You set a new score: " + setTimeText(time));
            window.draw(m_newScoreText);
        }
        else
        {
            m_timeText.setString("Time: " + setTimeText(time));
            window.draw(m_timeText);
        }
    }
    else
        window.draw(m_loseText);
}

bool EndLevelScreen::isContainRetry(sf::Event e)
{
    m_soundCounter = 0;
    return m_retryBtn.isContain(e);
}

bool EndLevelScreen::isContainMenu(sf::Event e)
{
    m_soundCounter = 0;
    return m_menuBtn.isContain(e);
}

bool EndLevelScreen::isContainNext(sf::Event e)
{
    m_soundCounter = 0;
    return m_nextLevelBtn.isContain(e);
}

void EndLevelScreen::createText()
{
    m_winText.setFont(*Resources::instance().getFont());
    m_winText.setCharacterSize(CHAR_SIZE);
    m_winText.setPosition(590, 295);
    m_winText.setColor(sf::Color::Black);
    m_winText.setString("Great! you won this level");

    m_timeText.setFont(*Resources::instance().getFont());
    m_timeText.setCharacterSize(CHAR_SIZE);
    m_timeText.setPosition(695, 375);
    m_timeText.setColor(sf::Color::Black);

    m_newScoreText.setFont(*Resources::instance().getFont());
    m_newScoreText.setCharacterSize(CHAR_SIZE - 5);
    m_newScoreText.setPosition(595, 375);
    m_newScoreText.setColor(sf::Color::Black);

    m_loseText.setFont(*Resources::instance().getFont());
    m_loseText.setCharacterSize(CHAR_SIZE);
    m_loseText.setPosition(645, 295);
    m_loseText.setColor(sf::Color::Black);
    m_loseText.setString("You lost this level\n    Try again!");
}

std::string EndLevelScreen::setTimeText(int time)
{
    int sec = time, min = 0;
    calcTime(sec, min);

    std::string timeStr = (min < 10 ? "0" : "") + std::to_string(min) + ":" + (sec < 10 ? "0" : "") + std::to_string(sec);

    return timeStr;
}

void EndLevelScreen::playSound(bool status)
{
    if (status && m_soundCounter == 0)
        m_winSound.playMusic();
    else if (!status && m_soundCounter == 0)
        m_loseSound.playMusic();

    ++m_soundCounter;
}

