#include "EndLevelScreen.h"

EndLevelScreen::EndLevelScreen()
: m_background(sf::Vector2f(END_WIDTH, END_HEIGHT)),
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
    m_buttons.emplace_back(Button(*Resources::instance().getEndLevelBtnsTexture(EndLevelButtonType::Retry), sf::Vector2f(150,70)));
    m_buttons.emplace_back(Button(*Resources::instance().getEndLevelBtnsTexture(EndLevelButtonType::Menu), sf::Vector2f(150,70)));
    m_buttons.emplace_back(Button(*Resources::instance().getEndLevelBtnsTexture(EndLevelButtonType::Next), sf::Vector2f(150,70)));

    auto start_x = 575;
    for (size_t i = 0; i < m_buttons.size(); i++)
    {
        m_buttons[i].setPosition(sf::Vector2f(start_x + 150 * i, WINDOW_HEIGHT - END_HEIGHT));
        m_buttons[i].setColor(sf::Color::White);
    }
}

void EndLevelScreen::draw(sf::RenderWindow &window, bool status, int levelNum, int time)
{
    playSound(status);

    window.draw(m_background);

    m_buttons[(int)EndLevelButtonType::Retry].draw(window);
    m_buttons[(int)EndLevelButtonType::Menu].draw(window);

    if (status && levelNum <= NUM_OF_LEVELS)
    {
        m_buttons[2].draw(window);

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
    if(m_buttons[(int)EndLevelButtonType::Retry].isContain(e))
    {
        m_soundCounter = 0;
        return true;
    }
    return false;
}

bool EndLevelScreen::isContainMenu(sf::Event e)
{
    if(m_buttons[(int)EndLevelButtonType::Menu].isContain(e))
    {
        m_soundCounter = 0;
        return true;
    }
    return false;
}

bool EndLevelScreen::isContainNext(sf::Event e)
{
    if(m_buttons[(int)EndLevelButtonType::Next].isContain(e))
    {
        m_soundCounter = 0;
        return true;
    }
    return false;
}

void EndLevelScreen::createText()
{
    m_winText.setFont(*Resources::instance().getFont());
    m_winText.setCharacterSize(CHAR_SIZE);
    m_winText.setPosition(590, 295);
    m_winText.setFillColor(sf::Color::Black);
    m_winText.setString("Great! you won this level");

    m_timeText.setFont(*Resources::instance().getFont());
    m_timeText.setCharacterSize(CHAR_SIZE);
    m_timeText.setPosition(695, 375);
    m_timeText.setFillColor(sf::Color::Black);

    m_newScoreText.setFont(*Resources::instance().getFont());
    m_newScoreText.setCharacterSize(CHAR_SIZE - 5);
    m_newScoreText.setPosition(595, 375);
    m_newScoreText.setFillColor(sf::Color::Black);

    m_loseText.setFont(*Resources::instance().getFont());
    m_loseText.setCharacterSize(CHAR_SIZE);
    m_loseText.setPosition(645, 295);
    m_loseText.setFillColor(sf::Color::Black);
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
        m_winSound.playAudio();
    else if (!status && m_soundCounter == 0)
        m_loseSound.playAudio();

    ++m_soundCounter;
}

void EndLevelScreen::handleHover(const sf::Vector2f& location)
{
    for (int i = 0; i < m_buttons.size(); ++i)
    {
        if (m_buttons[i].isHover(location))
            m_buttons[i].setColor(sf::Color({ 255, 255, 255, 180}));
        else
            m_buttons[i].setColor(sf::Color::White);
    }
}