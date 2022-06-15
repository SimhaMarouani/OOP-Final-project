#include "Screens/GameScreen.h"
#include "Controller.h"


GameScreen::GameScreen()
    : Screen(Resources::instance().getBackground(ScreenType::Game)),
      m_activePlayer(Player::Heavy),
      m_pageStatus(LevelActions::None), m_levelNum(1)
{
}

//-----------------------------------------------------------------

void GameScreen::draw(sf::RenderWindow& window) {
    Screen::draw(window);
    m_world.draw(window, m_activePlayer);
    m_dataDisplay.draw(window);

    ////== Box2d debugger view ==
    //DebugDraw d(&window);
    //uint32 flags = b2Draw::e_shapeBit;
    //d.SetFlags(flags);
    //m_world.getWorld()->SetDebugDraw(&d);
    //m_world.getWorld()->DebugDraw();

    //win/lose view
    if (getPageStatus() == LevelActions::Win)
        m_endLevelView->draw(window, true, m_levelNum, m_dataDisplay.getTime());
    else if(getPageStatus() == LevelActions::Lose)
        m_endLevelView->draw(window, false, m_levelNum, m_dataDisplay.getTime());

    if (m_pageStatus == LevelActions::Pause)
    {
        m_settingsView->draw(window, ScreenType::Game);
    }    
}

void GameScreen::processEvents(const sf::Event& event, sf::Vector2f &mouseLocation, Controller &controller)
{
    switch (event.type)
    {
    case sf::Event::KeyReleased:
    {
        handleKeyRelased(event.key.code, controller);   
        break;
    }
    case sf::Event::MouseButtonReleased:
        if (getPageStatus() == LevelActions::Win || getPageStatus() == LevelActions::Lose)
        {
            endLevelHandleClick(event, controller);
        }
        else if (m_pageStatus == LevelActions::None)
        {
            m_dataDisplay.handleClick(event, *this);
        }
        else if(m_pageStatus == LevelActions::Pause)
        {
            settingsHandleClick(event, controller);
        }
        break;

    case sf::Event::MouseMoved:
    {
        m_dataDisplay.handleHover(mouseLocation);
        m_endLevelView->handleHover(mouseLocation);
        m_settingsView->handleHover(mouseLocation);
        break;
    }
    default:
        break;
    }
}


void GameScreen::update(float deltaTime)
{
    if (m_pageStatus != LevelActions::Pause && m_pageStatus != LevelActions::Win && m_pageStatus != LevelActions::Lose)
    {
        m_world.moveActive(deltaTime, m_activePlayer);
        m_world.moveArrow(m_activePlayer);
    }
    else if(m_pageStatus == LevelActions::Pause)
        m_settingsView->update(ScreenType::Game);

    if (m_world.allPlayersReachedEnd())
    {
        updateStatus(LevelActions::Win);
        m_dataDisplay.pauseTimer();

        int time = m_dataDisplay.getTime();
        if(HighScore::instance().getLevelScore(m_levelNum) == -1 || time < HighScore::instance().getLevelScore(m_levelNum))
            HighScore::instance().addScore(m_levelNum, time);
    }
    else if (m_world.playerLost())
    {
        updateStatus(LevelActions::Lose);
        m_dataDisplay.pauseTimer();
    }
}

void GameScreen::resetTimer()
{
    m_dataDisplay.resetTimer();
}

void GameScreen::loadLevel(int level)
{
    m_levelNum = level;
    m_world.createLevel(level);
    m_dataDisplay.resetTimer();
}

void GameScreen::updateStatus(LevelActions la)
{
    m_pageStatus = la;
}

void GameScreen::initSettings(std::shared_ptr<Settings> s)
{
    m_settingsView = move(s);
}

void GameScreen::initEndLevelScreen(std::shared_ptr<EndLevelView> s)
{
    m_endLevelView = move(s);
}

void GameScreen::retryLevel()
{
    m_world.createLevel(m_levelNum);
    m_dataDisplay.resetTimer();
    m_activePlayer = Player::Heavy;
    m_dataDisplay.setCurrPlayer(static_cast<int>(m_activePlayer));
}

LevelActions GameScreen::getPageStatus() const
{
    return m_pageStatus;
}

void GameScreen::handleKeyRelased(enum sf::Keyboard::Key keyCode, Controller& controller)
{
    if (keyCode == sf::Keyboard::A && m_pageStatus == LevelActions::None)
    {
        m_activePlayer = Player((static_cast<int>(m_activePlayer) + 1) % NUM_OF_PLAYERS);
        m_dataDisplay.setCurrPlayer(static_cast<int>(m_activePlayer));
    }
    else if (keyCode == sf::Keyboard::Escape && m_pageStatus == LevelActions::None)
    {
        m_pageStatus = LevelActions::None;
        controller.updatePage(ScreenType::HomePage);
    }
}

void GameScreen::endLevelHandleClick(const sf::Event& e, Controller& controller)
{
    if (m_endLevelView->isContainRetry(e))
    {
        playClickAudio();
        retryLevel();
        updateStatus(LevelActions::None);
    }
    else if (m_endLevelView->isContainNext(e))
    {
        playClickAudio();
        ++m_levelNum;
        m_world.createLevel(m_levelNum);
        m_dataDisplay.resetTimer();
        m_activePlayer = Player::Heavy;
        m_dataDisplay.setCurrPlayer(static_cast<int>(m_activePlayer));
        updateStatus(LevelActions::None);
    }
    else if (m_endLevelView->isContainMenu(e))
    {
        playClickAudio();
        controller.updatePage(ScreenType::HomePage);
        updateStatus(LevelActions::None);
    }
}

void GameScreen::settingsHandleClick(const sf::Event& e, Controller& controller)
{
    m_settingsView->handleClick(e, ScreenType::Game);

    if (m_settingsView->isContainExit(e))
    {
        playClickAudio();
        updateStatus(LevelActions::None);
        m_dataDisplay.startTimer();
    }

    if (m_settingsView->isContainHome(e))
    {
        playClickAudio();
        updateStatus(LevelActions::None);
        m_dataDisplay.startTimer();
        controller.updatePage(ScreenType::HomePage);
    }
}


