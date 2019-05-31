#include "stage3game.h"

#include "player.h"
#include "stickman.h"
#include "config.h"
#include "pausedialog.h"
#include <iostream>

Stage3Game::Stage3Game(GameState* state)
    : Stage2Game(state)
{
    scoreboard = new ScoreBoard(new Coordinate(50, 50, Config::config()->getWorldHeight(), Config::config()->getWorldWidth()), "scoreboard");

}

void Stage3Game::render(QPainter &painter){
    if(state->getGameOver()){
        painter.setPen(Qt::red);
        QFont font("Times", 50, QFont::Bold);
        painter.setFont(font);
        painter.drawText(Config::config()->getWorldWidth()/2-50,Config::config()->getWorldHeight()/2, "GAMEOVER. Press 'Q' to restart");
        scoreboard->render(painter, state->getLevel(), state->getLife());
    }else{
        state->getBackground()->render(painter, true);
        state->getPlayer()->render(painter);
        state->getRootEntity()->render(painter);

        scoreboard->render(painter, state->getLevel(), state->getLife());
    }
}

void Stage3Game::renderBackground(QPainter &painter){
    state->getBackground()->render(painter, false);
}

void Stage3Game::paintEvent(QPaintEvent *event){
    // Update game
    state->getPlayer()->update(paused, 32);

    // Render game
    QPainter painter(this);
    render(painter);
}

//Stage3Game::~Stage3Game() {
//    delete state;
//}

void Stage3Game::keyPressEvent(QKeyEvent *event) {
    if(event->type()==QEvent::KeyPress){

        Stickman *stickman = Config::config()->getStickman();
        if(event->key()==Qt::Key_P) {

            pause();

            PauseDialog pause_dialog(&this->paused);
            pause_dialog.setModal(true);
            pause_dialog.setWindowTitle("Pause Screen");
            pause_dialog.exec();

        }
        if(event->key() == Qt::Key_Space) {
            state->getPlayer()->jump();
        }
        if(event->key() == Qt::Key_Left){
//            if(stickman->getXPosition()>10){
//                stickman->changeXPosition(stickman->getXPosition()-10);
//            }
        }
        if(event->key() == Qt::Key_Right){
            state->update(paused);
            scoreboard->update(paused || state->getPlayerColliding() || state->getGameOver(), 1);
//            if(stickman->getXPosition() < Config::config()->getWorldWidth()-10){
//                stickman->changeXPosition(stickman->getXPosition()+10);
//            }
        }
        if(event->key() == Qt::Key_Q){
//            music->stop();
            close();
        }
    }

}

void Stage3Game::keyReleaseEvent(QKeyEvent *event){
    if(event->type()==QEvent::KeyRelease){
        if(event->key() == Qt::Key_Right){
            state->update(false);
        }
    }
}



