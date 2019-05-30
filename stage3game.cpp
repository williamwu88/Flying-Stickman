#include "stage3game.h"

#include "player.h"
#include "stickman.h"
#include "config.h"
#include <iostream>

Stage3Game::Stage3Game(GameState* state)
    : Stage2Game(state)
{
    scoreboard = new ScoreBoard(new Coordinate(100, 100, Config::config()->getWorldHeight(), Config::config()->getWorldWidth()), "scoreboard");
}

void Stage3Game::render(QPainter &painter){
    if(state->getGameOver()){
        painter.drawText(100,200, "GAMEOVER. Press 'Q' to restart");
        scoreboard->render(painter);
    }else{
        Stage2Game::render(painter);

        scoreboard->render(painter);
    }
}

void Stage3Game::paintEvent(QPaintEvent *event){
    // Update game
    state->update(paused);

    scoreboard->update(paused || state->getPlayerColliding() || state->getGameOver(), 1);

    // Render game
    QPainter painter(this);
    render(painter);
}

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


