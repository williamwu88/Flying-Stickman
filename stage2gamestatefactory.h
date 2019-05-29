#pragma once

#include "gamestatefactory.h"

class Stage2GameStateFactory : public GameStateFactory {
public:
    Stage2GameStateFactory() = default;
    ~Stage2GameStateFactory() override = default;
    virtual GameState* createGameState() override;
};

