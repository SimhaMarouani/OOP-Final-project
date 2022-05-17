#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Macros.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
public:
	Button(/*sf::Texture &texture, */sf::Vector2f size);
	~Button() {};
	void draw(sf::RenderWindow& window);

	//get
	bool isContain(sf::Event event) const;

	//set sprite
	void setPosition(sf::Vector2f pos);
	void setColor(sf::Color color);

private:
	sf::RectangleShape m_button; //Noga: rectangle or Sprite?
};
