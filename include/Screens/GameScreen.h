#pragma once
#include <SFML/Graphics.hpp>

#include "World.h"
#include "DataDisplay.h"
#include "Settings.h"
#include "Screen.h"
#include "EndLevelView.h"
#include "HighScore.h"
#include "Audio.h"

class GameScreen : public Screen {
public:
	GameScreen();
	void draw(sf::RenderWindow& window);
	void processEvents(const sf::Event& event, sf::Vector2f &mouseLocation, Controller& controller);

	void update(float deltaTime);

	void resetTimer();
	void loadLevel(int level);
	void updateStatus(LevelActions la);

	void initSettings(std::shared_ptr<Settings> s);
	void initEndLevelScreen(std::shared_ptr<EndLevelView> s);
	void retryLevel();

	LevelActions getPageStatus() const;

private:
	void handleKeyRelased(enum sf::Keyboard::Key keyCode, Controller& controller);
	void endLevelHandleClick(const sf::Event& e, Controller& controller);
	void settingsHandleClick(const sf::Event& e, Controller& controller);

	World m_world;
	DataDisplay m_dataDisplay;

	std::shared_ptr<Settings> m_settingsView;
	std::shared_ptr<EndLevelView> m_endLevelView;

	LevelActions m_pageStatus;
	Player m_activePlayer;

    int m_levelNum;
};