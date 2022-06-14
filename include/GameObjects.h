#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Macros.h"
#include "Utilities.h"
#include "box2d/box2d.h"

class GameObjects
{
public:
    GameObjects();
    ~GameObjects();

    void draw(sf::RenderWindow& window);

    sf::Vector2f  convertB2VecToVec2f(b2Vec2 vec2f) const;
    sf::Vector2f getPosition()const;
    virtual void setPosition(sf::Vector2f pos);
    float getWidth()const;
    float getHeight()const;
    void createSquareBody(b2World* world, b2BodyType bodyType, sf::Vector2i rect = { 0, 0 });
    void createCircleBody(b2World* world, b2BodyType bodyType, float radius);
    void createSensor(b2World* world, float width, float height, b2Vec2 center, int data);

protected:
    b2Body* m_body = nullptr;
    sf::Sprite m_icon;
};