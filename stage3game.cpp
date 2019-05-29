#include "stage3game.h"

#include "player.h"
#include <iostream>

Stage3Game::Stage3Game(GameState* state)
    : Stage2Game(state) {}

//Stage3Game::~Stage3Game() {
//    delete state;
//}

void Stage3Game::keyPressEvent(QKeyEvent *event) {
    Stage2Game::keyPressEvent(event);

    if(event->type()==QEvent::KeyPress){
        if(event->key() == Qt::LeftArrow){
            // Make stickman move left
            Coordinate *player_position = state->getPlayer()->getPosition();
            if(player_position->getXCoordinate()>0){
                player_position->changeInXCoordinate(-10);
            }
            std::cout << "Left pressed" << std::endl;
        }else if(event->key() == Qt::RightArrow){
            // Make stickman move right
            Coordinate *player_position = state->getPlayer()->getPosition();
            if(player_position->getXCoordinate()<player_position->getFrameWidth()){
                player_position->changeInXCoordinate(10);
            }
            std::cout << "Right pressed" << std::endl;
        }
    }
}

