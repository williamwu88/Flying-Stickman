#include "startdialog.h"
#include "ui_startdialog.h"

#include "config.h"
#include "gamedialog.h"
#include "gamefactory.h"

#include <QKeyEvent>
#include <memory>
#include <QMediaPlayer>
#include <QMediaPlaylist>


StartDialog::StartDialog(GameFactory* gameFactory, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog),
    gameFactory(gameFactory) {

    ui->setupUi(this);
    // this->setStyleSheet("background-color: #FFFFFF;"); //White
    this->setFixedSize(this->width(), this->height());

    // Stage 3
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

    setUpUI();
}

StartDialog::~StartDialog() {
    delete ui;
    delete gameFactory;
}

void StartDialog::handleButton(){
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

//Sets up the start screen with the values from the config screen as well as the background options
void StartDialog::setUpUI() {

    QPixmap bg1_image(":img/background1/background.png");
    bg1_image = bg1_image.scaled(ui->bg1->width(), ui->bg1->height());
    ui->bg1->setPixmap(bg1_image);

    QPixmap bg2_image(":img/background2/background.png");
    bg2_image = bg2_image.scaled(ui->bg2->width(), ui->bg2->height());
    ui->bg2->setPixmap(bg2_image);

    if (Config::config()->getBackgroundNumber() == 1) {
        ui->bg1_radio->setChecked(true);
    } else {
        ui->bg2_radio->setChecked(true);
    }

    music->setPlaylist(playlist);
    music->play();
}


void StartDialog::on_bg1_radio_clicked() {
    Config::config()->setBackgroundNumber(1);
}

void StartDialog::on_bg2_radio_clicked() {
    Config::config()->setBackgroundNumber(2);
}

void StartDialog::on_start_clicked() {

    /*
     * Close the main menu dialog
     * Show the game dialog
    */

    close();

    auto game_dialog = std::unique_ptr<GameDialog>(gameFactory->createGame());
    game_dialog->setModal(true);
    game_dialog->setWindowTitle("Running Stickman");
    game_dialog->exec();

    show();
}

void StartDialog::keyPressEvent(QKeyEvent *event) {

    if (event->type()==QEvent::KeyPress) {

        QKeyEvent* key = static_cast<QKeyEvent*>(event);

        if ( (key->key()==Qt::Key_Q) ) { //P was pressed

            //Close the main menu dialog (meaning the whole game)
            close();

        }

    }
}

