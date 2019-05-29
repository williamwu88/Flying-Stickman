#ifndef STAGE3GAMESTATEFACTORY_H
#define STAGE3GAMESTATEFACTORY_H

#include "gamestatestage3.h"

class Stage3GameStateFactory {
public:
    Stage3GameStateFactory() = default;
    ~Stage3GameStateFactory() = default;
    virtual GameState* createGameState();
};

#endif // STAGE3GAMESTATEFACTORY_H
