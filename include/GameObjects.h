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

//    void draw(sf::RenderWindow& window) = 0;

private:
    float getWidth();
    float getHeight();
    void setBox2d(std::unique_ptr<b2World> &world, b2BodyType);
    b2Body* m_body = nullptr;
   
    sf::Sprite m_sprite;
};