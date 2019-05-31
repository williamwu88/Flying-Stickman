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

void Stage3Game::render(QPainter &painter){
    if(state->getGameOver()){
        painter.setPen(Qt::red);
        QFont font("Times", 50, QFont::Bold);
        painter.drawText(Config::config()->getWorldWidth()/2,Config::config()->getWorldHeight()/2, "GAMEOVER. Press 'Q' to restart");
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
    scoreboard->update(paused, stickman_dist_travelled);

    // Render game
    QPainter painter(this);
    render(painter);
}


//Stage3Game::~Stage3Game() {
//    delete state;
//}

void Stage3Game::keyPressEvent(QKeyEvent *event) {
//    std::cout << stickman_velocity << std::endl;
    if(event->type()==QEvent::KeyPress){
        Stickman *stickman = Config::config()->getStickman();
        if(!event->isAutoRepeat() && event->key() == Qt::Key_Left){
            pressedL = true;
            stickman->changeVelocity(-stickman_velocity);
        }
        if(!event->isAutoRepeat() && event->key() == Qt::Key_Right){
            pressedR = true;
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
            pressedL = false;
        }
        if(!event->isAutoRepeat() && event->key() == Qt::Key_Right){
            stickman->changeVelocity(0);
            pressedR = false;
        }

    }
}



