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
    stickman_velocity = Config::config()->getStickman()->getVelocity();
    Config::config()->getStickman()->changeVelocity(0);
}

Stage3Game::~Stage3Game() {
    delete scoreboard;
}

void Stage3Game::render(QPainter &painter){
    if(state->getGameOver()){
        QPixmap gameover(":img/pic/GAMEOVER.png");
        painter.drawPixmap(0, 0, Config::config()->getWorldWidth(), Config::config()->getWorldHeight(), gameover);

        scoreboard->render(painter, state->getLevel(), state->getLife());
    }else{
        Stage2Game::render(painter);

        scoreboard->render(painter, state->getLevel(), state->getLife());
    }
}

void Stage3Game::paintEvent(QPaintEvent *event){
    // Update game
    state->update(paused);
    stickman_dist_travelled += Config::config()->getStickman()->getVelocity()*state->getLevel();
    if(state->getLife() != 0){
        scoreboard->update(paused, stickman_dist_travelled);
    }


    // Render game
    QPainter painter(this);
    render(painter);
}

void Stage3Game::keyPressEvent(QKeyEvent *event) {
    if(event->type()==QEvent::KeyPress){
        Stickman *stickman = Config::config()->getStickman();
        if(!event->isAutoRepeat() && event->key() == Qt::Key_Left){
            // Stickman runs backwards
            stickman->changeVelocity(-stickman_velocity);
        }
        if(!event->isAutoRepeat() && event->key() == Qt::Key_Right){
            // Stickman runs forwards
            stickman->changeVelocity(stickman_velocity);
        }
        if(event->key() == Qt::Key_Q){
            close();
        }
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
    }
}

void Stage3Game::keyReleaseEvent(QKeyEvent *event){
    if(event->type()==QEvent::KeyRelease){
        Stickman *stickman = Config::config()->getStickman();

        if(!event->isAutoRepeat() && event->key() == Qt::Key_Left){
            stickman->changeVelocity(0);
        }
        if(!event->isAutoRepeat() && event->key() == Qt::Key_Right){
            stickman->changeVelocity(0);
        }
    }
}



