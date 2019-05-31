#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "compositeentity.h"

class ScoreBoard : public CompositeEntity{
public:
    ScoreBoard(Coordinate* position, std::string name);

    virtual void update(bool paused, double time_since_last_frame) override;
    void render(QPainter &painter) override;
    void render(QPainter &painter, unsigned int level, unsigned int life);

    void setScore(double score){ current_score = score; }

private:
    double current_score = 0;
};

#endif // SCOREBOARD_H
