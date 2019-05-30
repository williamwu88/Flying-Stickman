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

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    ScoreBoard* scoreboard;
};

#endif // STAGE3GAME_H
