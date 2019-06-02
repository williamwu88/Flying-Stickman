#pragma once

#include "compositeentity.h"

class Coordinate;

class Coordinate;

class Player : public CompositeEntity {

public:
    Player(Coordinate* position, std::string name);
    virtual void jump() = 0;

    // Stage 3 Exclusive
    virtual double getYVelocity() = 0;

};

