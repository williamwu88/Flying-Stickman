#ifndef GAMESTATESTAGE3_H
#define GAMESTATESTAGE3_H

#include "gamestate.h"
#include <string>
#include <vector>

class GameStateStage3 : public GameState {

public:
    GameStateStage3();
//    virtual ~GameStateStage3();

    void checkCollisionStatus();
    std::string checkCollisionObject();

protected:

private:
    bool victory;

};

#endif // GAMESTATESTAGE3_H
