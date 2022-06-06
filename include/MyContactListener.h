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

        void* bodyUserDataB = contact->GetFixtureA()->GetBody->GetUserData();
        auto objA = static_cast<GameObject*>(bodyUserDataB)
        void* fixtureUserDataB = contact->GetFixtureA()->GetUserData();

        if (!objA | !objB)
            return;

        /*
        CollisionHandler::instance().proccessCollision(*objA, *objB, 
            ((int)fixtureUserDataA == 1 || (int)fixtureUserDataB == 1) ? true : false);
        */





        //if ((int)fixtureUserData == 3)
        //    TOUCHING_GROUND = true;
        ////check if fixture B was the foot sensor
        //fixtureUserData = &contact->GetFixtureB()->GetUserData().pointer;
        //if ((int)fixtureUserData == 3)
        //    TOUCHING_GROUND = true;
    }

    void EndContact(b2Contact* contact) {
        ////check if fixture A was the foot sensor
        //void* fixtureUserData = &contact->GetFixtureA()->GetUserData().pointer;
        //if ((int)fixtureUserData == 3)
        //    TOUCHING_GROUND = false;
        ////check if fixture B was the foot sensor
        //fixtureUserData = &contact->GetFixtureB()->GetUserData().pointer;
        //if ((int)fixtureUserData == 3)
        //    TOUCHING_GROUND = false;

    }
};