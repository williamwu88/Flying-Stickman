#ifndef ITERATOR_H
#define ITERATOR_H

#include "obstacle.h"

class Iterator {
public:

    virtual Obstacle* getNext() = 0;
    virtual bool hasNext() = 0;

};

#endif // ITERATOR_H
