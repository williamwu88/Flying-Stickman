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
    stickman_velocity = getStickmanVelocity();
    Config::config()->getStickman()->changeVelocity(0);
}

void Stage3Test::render(QPainter &painter){

    Stage2Game::render(painter);

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
    state->update(paused);
    stickman_dist_travelled += Config::config()->getStickman()->getVelocity()*state->getLevel();
    scoreboard->update(paused, stickman_dist_travelled);

    // Render game
    QPainter painter(this);
    render(painter);
}


void Stage3Test::keyPressEvent(QKeyEvent *event) {

    if(event->type()==QEvent::KeyPress){
        Stickman *stickman = Config::config()->getStickman();
        if(!event->isAutoRepeat() && event->key() == Qt::Key_Left){
            std::cout << "L pressing" << std::endl;
            stickman->changeVelocity(-stickman_velocity);
        }
        if(!event->isAutoRepeat() && event->key() == Qt::Key_Right){
            std::cout << "R pressing" << std::endl;
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

void Stage3Test::keyReleaseEvent(QKeyEvent *event){
    if(event->type()==QEvent::KeyRelease){
        Stickman *stickman = Config::config()->getStickman();

        if(!event->isAutoRepeat() && event->key() == Qt::Key_Left){
            stickman->changeVelocity(0);
            std::cout << "L released" << std::endl;
        }
        if(!event->isAutoRepeat() && event->key() == Qt::Key_Right){
            stickman->changeVelocity(0);
            std::cout << "R released" << std::endl;
        }

    }
}


