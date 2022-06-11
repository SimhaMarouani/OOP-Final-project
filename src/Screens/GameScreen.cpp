#include "Screens/GameScreen.h"
#include "Controller.h"


GameScreen::GameScreen()
    : m_activePlayer(Player::Heavy), m_win(false), m_lose(false),
      m_background(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT)),
      m_btnsClick(Resources::instance().getAudioClick())
{
    m_background.setTexture(Resources::instance().getBackground(Screen::Game));
    //m_world.createLevel(m_levelNum);
}

//-----------------------------------------------------------------

void GameScreen::draw(sf::RenderWindow& window)
{
    window.draw(m_background);
	m_world.draw(window);
	m_dataDisplay.draw(window);

    DebugDraw d(&window);
    uint32 flags = b2Draw::e_shapeBit;
    d.SetFlags(flags);
    m_world.getWorld()->SetDebugDraw(&d);
    m_world.getWorld()->DebugDraw();

    if(m_win)
    {
        m_endLevelView->draw(window);
    }

    if (m_pageStatus == LevelActions::Pause)
    {
        m_settingsView->draw(window, Screen::Game);
    }    
}

//TODO : move part of this to new functions
void GameScreen::processEvents(sf::Event event, Controller &controller)
{
    switch (event.type)
    {
    case sf::Event::KeyReleased:
    {
        if (event.key.code == sf::Keyboard::P && m_pageStatus != LevelActions::Pause)
        {
            m_activePlayer = Player((int(m_activePlayer) + 1) % 3);
            m_dataDisplay.setCurrPlayer(int(m_activePlayer));
        }
        else if (event.key.code == sf::Keyboard::Escape)
        {
            m_pageStatus = LevelActions::None;
            controller.updatePage(Screen::HomePage);
        }
        break;
    }
    case sf::Event::MouseButtonReleased:
        if (m_win)
        {
            m_win = false;
            if (m_endLevelView->isContainRetry(event))
                retryLevel();
            else if (m_endLevelView->isContainNext(event))   //need to update the level num and reload a level
            {
                ++m_levelNum;
                m_world.createLevel(m_levelNum);
                m_dataDisplay.resetTimer();
                m_activePlayer = Player::Heavy;
                m_dataDisplay.setCurrPlayer((int)m_activePlayer);
            }
            else if (m_endLevelView->isContainMenu(event))
                controller.updatePage(Screen::HomePage);
        }
        if(m_pageStatus != LevelActions::Pause)
            m_dataDisplay.handleClick(event, *this);
        else
        {
            m_settingsView->handleClick(event, Screen::Game);

            if (!m_settingsView->isContain(event)) //Noga: temp
            {
                updateStatus(LevelActions::None);
                m_dataDisplay.startTimer();
            }

            if (m_settingsView->isContainExit(event))
            {
                playAudio(m_btnsClick);
                updateStatus(LevelActions::None);
                m_dataDisplay.startTimer();
            }

            if (m_settingsView->isContainHome(event))
            {
                playAudio(m_btnsClick);
                updateStatus(LevelActions::None);
                controller.updatePage(Screen::HomePage);
            }
        }
        break;
    default:
        break;
    }

}

//-----------------------------------------------------------------

void GameScreen::update(float deltaTime)
{
    if (m_pageStatus != LevelActions::Pause)
    {
        m_world.moveActive(deltaTime, m_activePlayer);
        m_world.moveArrow(m_activePlayer);
    }
    else
    {
        m_settingsView->update(Screen::Game);
    }

    if (m_world.allPlayersReachedEnd())
        m_win = true;
    else if (m_world.playerLost())
    {
        m_lose = true;
        std::cout << "loser" << std::endl;
    }
}

void GameScreen::resetTimer()
{
    m_dataDisplay.resetTimer();
}

void GameScreen::pauseTimer()
{
    m_dataDisplay.switchTimer();
}

void GameScreen::loadLevel(int level)
{
    m_levelNum = level;
    m_world.createLevel(level);
}

void GameScreen::setDirection(Direction dir)
{
    //m_world.setActiveDirection(dir, m_activePlayer);
}

void GameScreen::updateStatus(LevelActions la)
{
    m_pageStatus = la;
}

void GameScreen::initSettings(std::shared_ptr<Settings> s)
{
    m_settingsView = move(s);
}

void GameScreen::initEndLevelScreen(std::shared_ptr<EndLevelScreen> s)
{
    m_endLevelView = move(s);
}

void GameScreen::retryLevel()
{
    m_world.loadLevel(m_levelNum);
    m_dataDisplay.resetTimer();
    m_activePlayer = Player::Heavy;
    m_dataDisplay.setCurrPlayer((int)m_activePlayer);
}

LevelActions GameScreen::getPageStatus() const
{
    return m_pageStatus;
}

void GameScreen::playAudio(Audio& a)
{
    if (Resources::instance().isAudioOn())
        a.playMusic();
}

