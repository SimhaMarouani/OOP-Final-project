#pragma once
#include "box2d/box2d.h"
#include <cstdint>
#include "GameObjects.h"
#include"CollisionHandler.h"

class MyContactListener : public b2ContactListener
{
    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);
};