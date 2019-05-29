#ifndef VICTORYFLAG_H
#define VICTORYFLAG_H

#include "compositeentity.h"
#include "rectcollider.h"
#include <QPixmap>

class VictoryFlag : public CompositeEntity {
public:
    VictoryFlag(Coordinate* position, double width, double height, double velocity, double ending_position, std::string name);
    ~VictoryFlag() override = default;

    virtual RectCollider* getCollider() override { return &collider; }

    virtual void update(bool paused, double time_since_last_frame) override;
    virtual void render(QPainter &painter) override;

    bool isMoving() { return is_moving; }
private:
    RectCollider collider;
    double width;
    double height;
    double velocity;
    double dist_travelled;
    double ending_position;
    QPixmap pic;
    bool is_moving;
};

#endif // VICTORYFLAG_H
