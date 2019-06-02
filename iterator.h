#ifndef ITERATOR_H
#define ITERATOR_H

#include "obstacleStage3.h"

class Iterator {
public:
    Iterator() = default;
    virtual ~Iterator() = default;

    virtual ObstacleStage3* getNext() = 0;
    virtual bool hasNext() = 0;

};

#endif // ITERATOR_H
