#ifndef STAGE3GAMESTATEFACTORY_H
#define STAGE3GAMESTATEFACTORY_H

#include "gamestatefactory.h"

class Stage3GameStateFactory : public GameStateFactory {
public:
    Stage3GameStateFactory() = default;
    ~Stage3GameStateFactory() override = default;
    virtual GameState* createGameState() override;
};

#endif // STAGE3GAMESTATEFACTORY_H
