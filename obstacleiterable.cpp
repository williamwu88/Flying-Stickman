#include "obstacleiterable.h"

#include "obstacleiterator.h"

ObstacleIterable::ObstacleIterable(std::vector<ObstacleConfig *> obstacle_data)
    : obstacle_data(obstacle_data){

}

Iterator *ObstacleIterable::createIterator(double loop){
    return new ObstacleIterator(obstacle_data, loop);
}
