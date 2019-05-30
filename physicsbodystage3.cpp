#include "physicsbodystage3.h"

PhysicsBodyStage3::PhysicsBodyStage3(Coordinate* position)
    : position(position),
      a_y(0),
      v_y(0)
{}

PhysicsBodyStage3::~PhysicsBodyStage3(){
    delete position;
}

void PhysicsBodyStage3::apply(double timestep){
    if (position != nullptr) {
        position->changeInYCoordinate(v_y*timestep + 0.5*a_y*timestep*timestep);
        v_y += a_y*timestep;
    }
}

