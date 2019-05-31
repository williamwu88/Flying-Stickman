#ifndef STAGE3TEST_H
#define STAGE3TEST_H

#include "stage3game.h"

class Stage3Test : public Stage3Game {
public:
    Stage3Test(GameState* state);

    void render(QPainter &painter) override;
    void renderBackground(QPainter &painter);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    ScoreBoard* scoreboard;


};

#endif // STAGE3TEST_H
