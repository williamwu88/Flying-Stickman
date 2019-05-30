#ifndef PHYSICSBODYSTAGE3_H
#define PHYSICSBODYSTAGE3_H

#include "coordinate.h"

/**
 * @brief The PhysicsBodyStage3 class
 * Reduced functionality compared to PhysicsBody class in Stage 2
 */
class PhysicsBodyStage3{
public:
    PhysicsBodyStage3(Coordinate* position);
    ~PhysicsBodyStage3();

    void apply(double timestep);
    double getYAcceleration() {return a_y;}
    double getYVelocity() {return v_y;}
    void setYAcceleration(double acceleration) {a_y = acceleration;}
    void setYVelocity(double velocity) {v_y = velocity;}

    Coordinate* getPos(){ return position; }

private:
    Coordinate* position;
    double a_y;
    double v_y;
};

#endif // PHYSICSBODYSTAGE3_H
