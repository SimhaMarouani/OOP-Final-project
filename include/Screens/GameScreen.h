#pragma once
#include <SFML/Graphics.hpp>

#include "World.h"
#include "DataDisplay.h"
#include "Settings.h"
#include "Screen.h"
#include "EndLevelScreen.h"
#include "HighScore.h"
#include "Audio.h"

class GameScreen : public Screen {
public:
	GameScreen();
	void draw(sf::RenderWindow& window);
	void processEvents(sf::Event event, sf::Vector2f &mouseLocation, Controller& controller);

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

    int m_levelNum;
};