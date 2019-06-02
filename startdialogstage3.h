#ifndef STARTDIALOGSTAGE3_H
#define STARTDIALOGSTAGE3_H

#include <QDialog>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QPushButton>

#include "startdialog.h"

namespace Ui {
class StartDialogStage3;
}

class StartDialogStage3 : public StartDialog{
    Q_OBJECT

public:
    explicit StartDialogStage3(GameFactory* gameFactory, QWidget *parent = nullptr);

private slots:
    void handleButton();

private:
    bool mute;
    QMediaPlaylist *playlist;
    QMediaPlayer *music;

    QPushButton *m_button;

};

#endif // STARTDIALOGSTAGE3_H
