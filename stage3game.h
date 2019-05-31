#ifndef STAGE3GAME_H
#define STAGE3GAME_H

#include "stage1game.h"
#include "stage2game.h"
#include "gamestate.h"
#include "scoreboard.h"

class Stage3Game : public Stage2Game {
public:
    Stage3Game(GameState* state);
//    ~Stage3Game() override;

    void render(QPainter &painter) override;
    void renderBackground(QPainter &painter);

    double getStickmanVelocity() {return stickman_velocity;}

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

//private slots:
//    void handleButton();

private:
    ScoreBoard* scoreboard;

    double stickman_velocity = 0;
    bool pressedL = false;
    bool pressedR = true;

    double stickman_dist_travelled = 0;

};

#endif // STAGE3GAME_H
