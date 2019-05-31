#include "stage3testfactory.h"

#include "stage3game.h"
#include "stage3test.h"
#include "stage3gamestatefactory.h"

GameDialog *Stage3TestFactory::createGame(){
    Stage3GameStateFactory* factory = new Stage3GameStateFactory();
    GameState* state = factory->createGameState();
    return new Stage3Test(state);
}
