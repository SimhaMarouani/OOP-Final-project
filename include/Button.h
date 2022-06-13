#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Macros.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
public:
	Button(sf::Texture& texture, float scale);
	Button(sf::Texture& texture, sf::Vector2f size);
	Button(sf::Texture &texture);
	Button() {};
	virtual ~Button() = default;
	void draw(sf::RenderWindow& window);

	//get
	bool isContain(sf::Event event) const;
	sf::Vector2f getSize()const;
	bool isHover(sf::Vector2f l) const;
	//set sprite
	void setPosition(sf::Vector2f pos);
	void setTexture(sf::Texture* texture);
	void setColor(sf::Color color);
	void setSize(sf::Vector2f size);
	void setScale(sf::Vector2f scale);

private:
	sf::Sprite m_button;
};
