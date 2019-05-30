#include "victoryflag.h"

#include "coordinate.h"
#include <iostream>

VictoryFlag::VictoryFlag(Coordinate* position, double width, double height, double velocity, double ending_position, std::string name)
    : CompositeEntity (position, name),
      collider(RectCollider(new Coordinate(position->getXCoordinate() - width/2.0, position->getYCoordinate() - height/2.0, position->getFrameHeight(), position->getFrameWidth()),
                            new Coordinate(position->getXCoordinate() + width/2.0, position->getYCoordinate() + height/2.0, position->getFrameHeight(), position->getFrameWidth()))),
      velocity(velocity),
      dist_travelled(0),
      ending_position(ending_position),
      pic(QPixmap(QString(":img/pic/victory-flag.png"))),
      is_moving(true){

    if (width > 0) {
        this->width = width;
    } else {
        this->width = 1;
    }

    if (height > 0) {
        this->height = height;
    } else {
        this->height = 1;
    }
}

void VictoryFlag::update(bool paused, double time_since_last_frame){

    if(!paused) {
        setVelocity();

        if(this->getPosition()->getXCoordinate()<0){
            dist_travelled = 0;
            this->getPosition()->changeInXCoordinate(ending_position);
        }
        if(dist_travelled >= ending_position){
            this->getPosition()->changeInXCoordinate(velocity);
        }

        collider.getV1()->setXCoordinateToZero(getPosition()->getXCoordinate());
        collider.getV1()->setYCoordinateToZero(getPosition()->getYCoordinate() - height/2.0);
        collider.getV2()->setXCoordinateToZero(getPosition()->getXCoordinate());
        collider.getV2()->setYCoordinateToZero(getPosition()->getYCoordinate() + height/2.0);

        updateChildren(paused, time_since_last_frame);

        std::cout << dist_travelled << "," << ending_position << std::endl;

        dist_travelled -= velocity;
    }
}

void VictoryFlag::render(QPainter &painter){
    if(getPosition() != nullptr){
        double x = this->getPosition()->getQtRenderingXCoordinate();
        double y = this->getPosition()->getQtRenderingYCoordinate();
        painter.drawPixmap(x, 0, 100, this->getPosition()->getFrameHeight(), pic);
    }

    renderChildren(painter);
}
