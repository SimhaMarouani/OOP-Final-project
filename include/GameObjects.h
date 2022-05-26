#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Macros.h"
#include "box2d/box2d.h"


class GameObjects
{
public:
    GameObjects();

    virtual ~GameObjects() = default;
    sf::Vector2f  convertB2VecToVec2f(b2Vec2 vec2f) const;
//    void draw(sf::RenderWindow& window) = 0;

protected:
    void setBox2d(std::unique_ptr<b2World> &world, b2BodyType);
    b2Body* m_body = nullptr;
    float getWidth();
    float getHeight();
    sf::Vector2f getPosition();
   
    sf::Sprite m_sprite;
};