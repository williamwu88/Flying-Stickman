#ifndef STAGE3GAME_H
#define STAGE3GAME_H

#include "stage1game.h"
#include "stage2game.h"
#include "gamestate.h"

class Stage3Game : public Stage2Game {
public:
    Stage3Game(GameState* state);
//    ~Stage3Game() override;

protected:
//    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

//    GameState* state;
//    bool player_colliding;
};

#endif // STAGE3GAME_H
