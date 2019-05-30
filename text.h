#ifndef TEXT_H
#define TEXT_H

#include <QPainter>
#include "compositeentity.h"

class Text : public CompositeEntity{
public:
    Text(Coordinate* position, std::string name);
    ~Text() override = default;

    virtual void update(bool paused, double time_since_last_frame) override = 0;
    virtual void render(QPainter &painter) override = 0;

};

#endif // TEXT_H
