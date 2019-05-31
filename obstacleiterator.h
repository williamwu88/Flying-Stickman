#ifndef OBSTACLEITERATOR_H
#define OBSTACLEITERATOR_H

#include "iterator.h"
#include "extendedconfigstage3.h"

class ObstacleIterator : public Iterator{
public:
    ObstacleIterator(std::vector<ObstacleConfig*> obstacle_data, double loop);
    virtual ~ObstacleIterator() = default;

    Obstacle* getNext();
    bool hasNext();

    void resetIterator(){index = 0;}

private:
    std::vector<Obstacle*> obstacles;
    unsigned int index = 0;

};

#endif // OBSTACLEITERATOR_H
