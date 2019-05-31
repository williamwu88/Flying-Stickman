#ifndef GAMESTATESTAGE3_H
#define GAMESTATESTAGE3_H

#include "gamestate.h"
#include "scoreboard.h"
#include <string>
#include <vector>
#include <QSound>

class GameStateStage3 : public GameState {

public:
    GameStateStage3();
//    virtual ~GameStateStage3();

    // Stage 3 exclusive
    Entity* checkCollisionObject();

    void checkCollisions() override;
    void update(bool paused) override;

    bool getGameOver() override {return gameover;}
    unsigned int getLevel() override {return level;}
    unsigned int getLife() override {return life;}
    void setLife(unsigned int number) override { life = number; }

    void resetScene();

protected:

private:
    unsigned int life = 5;
    unsigned int level = 1;
    double default_velocity;
    double current_velocity;

    bool gameover = false;
    bool obstacle_collided = false;
    bool victory_flag_collided = false;

    QSound giant_explode;
    QSound lose_life;
    QSound victory;

};

#endif // GAMESTATESTAGE3_H
