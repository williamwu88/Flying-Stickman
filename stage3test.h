#ifndef STAGE3TEST_H
#define STAGE3TEST_H

#include "stage3game.h"

class Stage3Test : public Stage3Game {
public:
    Stage3Test(GameState* state);
    ~Stage3Test() override;

    void render(QPainter &painter) override;
    void renderBackground(QPainter &painter);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    ScoreBoard* scoreboard;

    double stickman_velocity = 0;
    double stickman_dist_travelled = 0;

    bool pressedL = false;
    bool pressedR = true;
};

#endif // STAGE3TEST_H
