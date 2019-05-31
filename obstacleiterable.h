#ifndef ITERABLEOBSTACLE_H
#define ITERABLEOBSTACLE_H

#include "obstacle.h"
#include "iterator.h"
#include "extendedconfigstage3.h"

class ObstacleIterable{
public:
    ObstacleIterable(std::vector<ObstacleConfig*> obstacle_data);

    Iterator* createIterator(double loop);

private:
    std::vector<ObstacleConfig*> obstacle_data;
};

#endif // ITERABLEOBSTACLE_H
