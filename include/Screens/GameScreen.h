#pragma once
#include <SFML/Graphics.hpp>

#include "World.h"
#include "DataDisplay.h"
#include "Settings.h"


class GameScreen {
public:
	GameScreen();
	void draw(sf::RenderWindow& window);
	void processEvents(sf::Event event, Controller& controller);

	void update(float deltaTime);

	void resetTimer();
	void pauseTimer();
	void loadLevel(int level);
	void setDirection(Direction dir);
	void updateStatus(LevelActions la);

	void initSettings(std::shared_ptr<Settings> s);
private:
	World m_world;
	DataDisplay m_dataDisplay;

	std::shared_ptr<Settings> m_settingsView;

	LevelActions m_pageStatus;
	Player m_activePlayer;

	sf::RectangleShape m_background;

};