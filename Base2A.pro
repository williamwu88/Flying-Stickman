#-------------------------------------------------
#
# Project created by QtCreator 2019-03-21T10:11:29
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = Base2A
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    coordinate.cpp \
    stickman.cpp \
    config.cpp \
    background.cpp \
    pausedialog.cpp \
    gamedialog.cpp \
    startdialog.cpp \
    gamefactory.cpp \
    stage1game.cpp \
    extendedconfig.cpp \
    stage2gamefactory.cpp \
    stage2game.cpp \
    gamestate.cpp \
    obstacle.cpp \
    entity.cpp \
    compositeentity.cpp \
    leafentity.cpp \
    player.cpp \
    stickmanplayer.cpp \
    physicsbody.cpp \
    rectcollider.cpp \
    emptyentity.cpp \
    tester.cpp \
    gamestatefactory.cpp \
    stage2gamestatefactory.cpp \
    stage3game.cpp \
    stage3gamefactory.cpp \
    stage3gamestatefactory.cpp \
    extendedconfigstage3.cpp \
    victoryflag.cpp \
    gamestatestage3.cpp \
    stickmanplayerstage3.cpp \
    physicsbodystage3.cpp \
    text.cpp \
    scoreboard.cpp

HEADERS += \
    coordinate.h \
    stickman.h \
    config.h \
    background.h \
    pausedialog.h \
    gamedialog.h \
    startdialog.h \
    gamefactory.h \
    stage1gamefactory.h \
    stage1game.h \
    extendedconfig.h \
    configuration.h \
    stage2gamefactory.h \
    stage2game.h \
    gamestate.h \
    obstacle.h \
    entity.h \
    compositeentity.h \
    leafentity.h \
    player.h \
    stickmanplayer.h \
    physicsbody.h \
    rectcollider.h \
    emptyentity.h \
    tester.h \
    gamestatefactory.h \
    stage2gamestatefactory.h \
    stage3game.h \
    stage3gamefactory.h \
    stage3gamestatefactory.h \
    extendedconfigstage3.h \
    victoryflag.h \
    gamestatestage3.h \
    stickmanplayerstage3.h \
    physicsbodystage3.h \
    text.h \
    scoreboard.h

FORMS += \
    pausedialog.ui \
    startdialog.ui \
    gamedialog.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    config.txt
