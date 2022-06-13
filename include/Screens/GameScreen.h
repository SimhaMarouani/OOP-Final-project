#pragma once
#include <SFML/Graphics.hpp>

#include "World.h"
#include "DataDisplay.h"
#include "Settings.h"
#include "EndLevelScreen.h"
#include "HighScore.h"
#include "Audio.h"

class GameScreen {
public:
	GameScreen();
	void draw(sf::RenderWindow& window);
	void processEvents(sf::Event event, Controller& controller);

	void update(float deltaTime);

	void resetTimer();
	void pauseTimer();
	void loadLevel(int level);
	void updateStatus(LevelActions la);

	void initSettings(std::shared_ptr<Settings> s);
	void initEndLevelScreen(std::shared_ptr<EndLevelScreen> s);
	void retryLevel();

	LevelActions getPageStatus() const;

private:
	World m_world;
	DataDisplay m_dataDisplay;

	std::shared_ptr<Settings> m_settingsView;
	std::shared_ptr<EndLevelScreen> m_endLevelView;

	LevelActions m_pageStatus;
	Player m_activePlayer;

	sf::RectangleShape m_background;

    int m_levelNum;
    
	Audio m_btnsClick;
};