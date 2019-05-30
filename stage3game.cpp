#include "stage3game.h"

#include "player.h"
#include "stickman.h"
#include "config.h"
#include <iostream>

Stage3Game::Stage3Game(GameState* state)
    : Stage2Game(state) {}

//void Stage3Game::paintEvent(QPaintEvent *event){
//    state->update(this);
//}

//Stage3Game::~Stage3Game() {
//    delete state;
//}

void Stage3Game::keyPressEvent(QKeyEvent *event) {
    Stage2Game::keyPressEvent(event);

    if(event->type()==QEvent::KeyPress){
        Stickman *stickman = Config::config()->getStickman();

        if(event->key() == Qt::Key_Left){
            // Make stickman move left
            std::cout << "Left pressed" << std::endl;
            if(stickman->getXPosition()>10){
                stickman->changeXPosition(stickman->getXPosition()-10);
            }
        }else if(event->key() == Qt::Key_Right){
            // Make stickman move right
            std::cout << "Right pressed" << std::endl;
            if(stickman->getXPosition() < Config::config()->getWorldWidth()-10){
                stickman->changeXPosition(stickman->getXPosition()+10);
            }
        }
    }
}


