#include "stage3test.h"

#include "player.h"
#include "stickman.h"
#include "config.h"
#include "pausedialog.h"
#include <iostream>
#include <sstream>

Stage3Test::Stage3Test(GameState* state)
    : Stage3Game(state)
{
    scoreboard = new ScoreBoard(new Coordinate(50, 50, Config::config()->getWorldHeight(), Config::config()->getWorldWidth()), "scoreboard");
}

void Stage3Test::render(QPainter &painter){

    state->getPlayer()->render(painter);
    state->getRootEntity()->render(painter);

    scoreboard->render(painter, state->getLevel(), state->getLife());

    //Testing interface
    painter.setPen(Qt::green);
    QFont font("Helvetica", 20, QFont::Bold);
    painter.setFont(font);

    std::stringstream colliding_status;
    colliding_status << "Colliding_status: " << state->getPlayerColliding();

    QString board = QString::fromStdString(colliding_status.str());

    painter.drawText(static_cast<int>(700),
                     static_cast<int>(50),
                     board);

    std::stringstream current_y_velocity;
    current_y_velocity << "Current y velocity: " << state->getPlayer()->getYVelocity();
    QString y_board = QString::fromStdString(current_y_velocity.str());
    painter.drawText(static_cast<int>(700),
                     static_cast<int>(50+20),
                     y_board);

    std::stringstream current_x_velocity;
    current_x_velocity << "Current x velocity: " << Config::config()->getStickman()->getVelocity();
    QString x_board = QString::fromStdString(current_x_velocity.str());
    painter.drawText(static_cast<int>(700),
                     static_cast<int>(50+40),
                     x_board);

}


void Stage3Test::paintEvent(QPaintEvent *event){
    // Update game
    state->getPlayer()->update(paused, 32);

    // Render game
    QPainter painter(this);
    render(painter);
}

//Stage3Game::~Stage3Game() {
//    delete state;
//}

void Stage3Test::keyPressEvent(QKeyEvent *event) {
    if(event->type()==QEvent::KeyPress){

//        Stickman *stickman = Config::config()->getStickman();
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

void Stage3Test::keyReleaseEvent(QKeyEvent *event){
    if(event->type()==QEvent::KeyRelease){
        if(event->key() == Qt::Key_Right){
            state->update(false);
        }
    }
}

