#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Macros.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
public:
	Button(const sf::Texture& texture, float scale);
	Button(const sf::Texture& texture, const sf::Vector2f &size);
	Button(const sf::Texture &texture);
	Button() {};
	virtual ~Button() = default;

	void draw(sf::RenderWindow& window);

	//get data
	bool isContain(const sf::Event event) const;
	const sf::Vector2f& getSize() const;
	bool isHover(const sf::Vector2f l) const;

	//set sprite
	void setPosition(const sf::Vector2f &pos);
	void setTexture(const sf::Texture* texture);
	void setColor(const sf::Color &color);
	void setSize(const sf::Vector2f &size);
	void setScale(const sf::Vector2f &scale);

private:
	sf::Sprite m_button;
};
