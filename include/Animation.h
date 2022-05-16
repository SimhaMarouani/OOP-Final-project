#pragma once
#include <SFML/Graphics.hpp>

class Animation {
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	void update(int row, int totalImages, float deltaTime);

	sf::IntRect m_uvRect;
private:
	sf::Vector2u m_imageCount;
	sf::Vector2u m_currentImage;

	int m_totalImages;
	int m_displayed;

	float m_totalTime;
	float m_switchTime;
};