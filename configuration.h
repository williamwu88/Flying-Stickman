#pragma once

#include <vector>

struct ObstacleConfig {
    double width;
    double height;
    double offset_x;
    double position_y;
    int colour_red;
    int colour_green;
    int colour_blue;
};

class Configuration {
public:
    virtual ~Configuration() = default;
    virtual unsigned int getWorldWidth() = 0;
    virtual unsigned int getWorldHeight() = 0;
    virtual std::vector<ObstacleConfig*> getObstacleData() = 0;

protected:
    virtual void setupConfig() = 0;

};


