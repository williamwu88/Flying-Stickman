#include "startdialogstage3.h"

StartDialogStage3::StartDialogStage3(GameFactory* gameFactory, QWidget *parent)
    : StartDialog (gameFactory, parent)
{
    mute = false;
    playlist = new QMediaPlaylist();
    music = new QMediaPlayer();
    playlist->addMedia(QUrl("qrc:/sound/background_music.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    m_button = new QPushButton("", this);
    m_button->setGeometry(QRect(QPoint(this->width()-50, 0),QSize(50, 50)));
    m_button->setFlat(true);
    QIcon icon2;
    icon2.addFile(QString::fromUtf8(":img/music/unmute.png"), QSize(), QIcon::Normal, QIcon::Off);
    m_button->setIcon(icon2);
    m_button->setIconSize(QSize(50, 50));
    connect(m_button, SIGNAL (released()), this, SLOT (handleButton()));

    music->setPlaylist(playlist);
    music->play();
}

void StartDialogStage3::handleButton(){
    if(mute){
        music->play();
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":img/music/unmute.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_button->setIcon(icon2);
        m_button->setIconSize(QSize(50, 50));
    }else{
        music->stop();
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":img/music/mute.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_button->setIcon(icon2);
        m_button->setIconSize(QSize(50, 50));
    }
    mute = !mute;
}
