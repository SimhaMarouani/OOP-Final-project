#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "Audio.h"

#include "Macros.h"
#include "Resources.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class Controller;

class Screen {
public:
	Screen(const sf::Texture *t);
	Screen() = default;
	virtual ~Screen() = default;
	
	virtual void processEvents(const sf::Event& event, sf::Vector2f& mouseLocation, Controller& controller) = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window);

	void setBackgroundColor(const sf::Color& c) { m_background.setFillColor(c); };
	void playClickAudio();
private:
	sf::RectangleShape m_background;
	Audio m_btnAudio;
};
