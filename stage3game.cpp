#include "stage3game.h"

#include "player.h"
#include "stickman.h"
#include "config.h"
#include "pausedialog.h"
#include <iostream>

Stage3Game::Stage3Game(GameState* state)
    : Stage2Game(state)
{
    scoreboard = new ScoreBoard(new Coordinate(100, 100, Config::config()->getWorldHeight(), Config::config()->getWorldWidth()), "scoreboard");

//    playlist = new QMediaPlaylist();
//    playlist->setPlaybackMode(QMediaPlaylist::Loop);
//    music = new QMediaPlayer();

//    mute = false;
//    playlist = new QMediaPlaylist();
//    music = new QMediaPlayer();
//    playlist->setPlaybackMode(QMediaPlaylist::Loop);

//    m_button = new QPushButton("", this);
//    m_button->setAutoDefault(false);
//    m_button->setEnabled(true);

//    m_button->setGeometry(QRect(QPoint(this->width()-50, 0),QSize(50, 50)));
//    m_button->setFlat(true);
//    QIcon icon;
//    icon.addFile(QString::fromUtf8(":img/music/unmute.png"), QSize(), QIcon::Normal, QIcon::Off);
//    m_button->setIcon(icon);
//    m_button->setIconSize(QSize(50, 50));
//    connect(m_button, SIGNAL (released()), this, SLOT (handleButton()));

//    if(Config::config()->getBackgroundNumber()==1){
//        playlist->addMedia(QUrl("qrc:/sound/background_music.wav"));
//        music->setPlaylist(playlist);
//        music->play();
//    }else{
//        playlist->addMedia(QUrl("qrc:/sound/Netherplace.mp3"));
//        music->setPlaylist(playlist);
//        music->play();
//    }
}

void Stage3Game::render(QPainter &painter){
    if(state->getGameOver()){
        painter.drawText(100,200, "GAMEOVER. Press 'Q' to restart");
        scoreboard->render(painter, state->getLevel(), state->getLife());
    }else{
        Stage2Game::render(painter);

        scoreboard->render(painter, state->getLevel(), state->getLife());
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
            // Make stickman jump
            state->getPlayer()->jump();
        }
        if(event->key() == Qt::Key_Left){
            // Make stickman move left
            std::cout << "Left pressed" << std::endl;
            if(stickman->getXPosition()>10){
                stickman->changeXPosition(stickman->getXPosition()-10);
            }
        }
        if(event->key() == Qt::Key_Right){
            // Make stickman move right
            std::cout << "Right pressed" << std::endl;
            if(stickman->getXPosition() < Config::config()->getWorldWidth()-10){
                stickman->changeXPosition(stickman->getXPosition()+10);
            }
        }
        if(event->key() == Qt::Key_Q){
//            music->stop();
            close();
        }
    }

}

//void Stage3Game::handleButton(){
//    std::cout << "Inside game Dialog" << std::endl;

//    if(mute){
//        music->play();
//        QIcon icon2;
//        icon2.addFile(QString::fromUtf8(":img/music/unmute.png"), QSize(), QIcon::Normal, QIcon::Off);
//        m_button->setIcon(icon2);
//        m_button->setIconSize(QSize(50, 50));
//    }else{
//        music->stop();
//        QIcon icon2;
//        icon2.addFile(QString::fromUtf8(":img/music/mute.png"), QSize(), QIcon::Normal, QIcon::Off);
//        m_button->setIcon(icon2);
//        m_button->setIconSize(QSize(50, 50));
//    }
//    mute = !mute;
//}


