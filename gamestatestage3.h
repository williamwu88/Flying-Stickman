#ifndef GAMESTATESTAGE3_H
#define GAMESTATESTAGE3_H

#include "gamestate.h"
#include "scoreboard.h"
#include <string>
#include <vector>

class GameStateStage3 : public GameState {

public:
    GameStateStage3();
//    virtual ~GameStateStage3();

    // Stage 3 exclusive
    Entity* checkCollisionObject();

    void checkCollisions() override;
    void update(bool paused) override;

    bool getGameOver() override {return gameover;}

protected:

private:
    unsigned int life = 5;

    bool gameover = false;
    bool obstacle_collided = false;
    bool victory_flag_collided = false;

};

#endif // GAMESTATESTAGE3_H
