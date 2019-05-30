#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "text.h"


class ScoreBoard : public Text{
public:
    ScoreBoard(Coordinate* position, std::string name);

    virtual void update(bool paused, double time_since_last_frame) override;
    virtual void render(QPainter &painter) override;

    void setScore(double score){ current_score = score; }

private:
    double current_score;
};

#endif // SCOREBOARD_H
