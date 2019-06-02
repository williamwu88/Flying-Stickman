#ifndef OBSTACLESTAGE3_H
#define OBSTACLESTAGE3_H

#include "obstacle.h"

class ObstacleStage3 : public Obstacle {

public:
    ObstacleStage3(Coordinate* position, double width, double height, double velocity, double loop_after, QColor colour, std::string name);
    ~ObstacleStage3() override = default;

    virtual void onCollision(Entity *e) override;


};

#endif // OBSTACLESTAGE3_H
