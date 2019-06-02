#include "obstaclestage3.h"


ObstacleStage3::ObstacleStage3(Coordinate *position, double width, double height, double velocity, double loop_after, QColor colour, std::string name)
    : Obstacle(position, width, height, velocity, loop_after, colour, name)
{}

void ObstacleStage3::onCollision(Entity *e){
    if(e->getName() == "stickman" && Config::config()->getStickman()->getSize()=="giant"){
        setDist_travelled(getLoopAfter());
    }
}
