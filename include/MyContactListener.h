#pragma once
#include "box2d/box2d.h"
#include "Macros.h"
#include <cstdint>

class MyContactListener : public b2ContactListener
{
    void BeginContact(b2Contact* contact) {
        //check if fixture A was the foot sensor
        void* bodyUserDataA = contact->GetFixtureA()->GetBody->GetUserData();
        auto objA = static_cast<GameObject*>(bodyUserDataA)
        void* fixtureUserDataA = contact->GetFixtureA()->GetUserData();

        void* bodyUserDataB = contact->GetFixtureB()->GetBody->GetUserData();
        auto objA = static_cast<GameObject*>(bodyUserDataB)
        void* fixtureUserDataB = contact->GetFixtureB()->GetUserData();

        if (!objA | !objB)
            return;

        /*
        CollisionHandler::instance().proccessCollision(*objA, *objB, 
            ((int)fixtureUserDataA == 1 || (int)fixtureUserDataB == 1) ? true : false);
        */


    
    }

    void EndContact(b2Contact* contact) {


    }
};