#pragma once
#include <SFML/Graphics.hpp>

#include "World.h"
#include "DataDisplay.h"

class GameScreen {
public:
	GameScreen();
	void draw(sf::RenderWindow& window);
	void processEvents(sf::Event event, Controller& controller);

	void update(float deltaTime);

	void resetTimer();
	bool isEscPressed();
	void loadLevel(int level);
	void setDirection(Direction dir);

private:


	World m_world;
	DataDisplay m_dataDisplay;
	Player m_activePlayer;

	bool m_escPressed;
};