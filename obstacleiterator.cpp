#include "obstacleiterator.h"

#include "coordinate.h"
#include <sstream>

ObstacleIterator::ObstacleIterator(std::vector<ObstacleConfig *> obstacle_data, double loop){
    unsigned int world_height = Config::config()->getWorldHeight();
    unsigned int world_width = Config::config()->getWorldWidth();

    double previous_x = world_width;
    int count = 0;

    for (auto *obstacleConfig: obstacle_data){
        previous_x = previous_x + obstacleConfig->offset_x;
        std::stringstream name;
        name << "obstacle_" << count;
        Coordinate* obs_pos = new Coordinate(previous_x, obstacleConfig->position_y, world_height, world_width);
        Obstacle* obs = new Obstacle(obs_pos, obstacleConfig->width, obstacleConfig->height,
                                     -Config::config()->getStickman()->getVelocity(), loop,
                                     QColor(std::rand() % 255, std::rand() % 255, std::rand() % 255), name.str());
        count++;

        obstacles.push_back(obs);
    }
}

Obstacle *ObstacleIterator::getNext(){
    Obstacle* obs = obstacles.at(index);
    index++;
    return obs;
}

bool ObstacleIterator::hasNext(){
    return index < obstacles.size();
}


