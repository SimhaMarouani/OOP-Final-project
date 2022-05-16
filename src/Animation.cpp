#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	m_displayed = 0;

	m_imageCount = imageCount;
	m_switchTime = switchTime;

	m_totalTime = 0.0f;
	m_currentImage.x = 0;

	m_uvRect.width = texture->getSize().x / float(imageCount.x);
	m_uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation() 
{
}

void Animation::update(int row, int totalImages, float deltaTime)
{
	m_totalImages = totalImages - 1;
	m_currentImage.y = (row - 1) + floor(m_displayed / m_imageCount.x);
	m_totalTime += deltaTime;

	if (m_totalTime >= m_switchTime)
	{
		m_totalTime -= m_switchTime;
		m_currentImage.x++;
		m_displayed++;

		if (m_currentImage.x >= m_imageCount.x)
		{
			m_currentImage.x = 0;
		}

		if (m_totalImages < m_displayed)
		{
			m_displayed = 0;
			m_currentImage.x = 0;
			m_currentImage.y = 0;
		}
	}

	m_uvRect.left = m_currentImage.x * m_uvRect.width;
	m_uvRect.top = m_currentImage.y * m_uvRect.height;
}
