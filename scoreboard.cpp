#include "scoreboard.h"

#include "coordinate.h"
#include <iostream>
#include <sstream>

ScoreBoard::ScoreBoard(Coordinate *position, std::string name)
    : CompositeEntity(position, name){}

void ScoreBoard::update(bool paused, double dist_travelled){

    if (!paused) {
        setScore(dist_travelled);
    }

}

void ScoreBoard::render(QPainter &painter){
    std::stringstream score;
    score << "Score: " << current_score;

    QString board = QString::fromStdString(score.str());

    painter.drawText(static_cast<int>(this->getPosition()->getXCoordinate()),
                     static_cast<int>(this->getPosition()->getYCoordinate()),
                     board);
}

void ScoreBoard::render(QPainter &painter, unsigned int level, unsigned int life){

    painter.setPen(Qt::red);
    QFont font("Helvetica", 20, QFont::Bold);
    painter.setFont(font);

    std::stringstream score;
    score << "Score: " << current_score;

    QString board = QString::fromStdString(score.str());

    painter.drawText(static_cast<int>(this->getPosition()->getXCoordinate()),
                     static_cast<int>(this->getPosition()->getYCoordinate()),
                     board);

    std::stringstream s_level;
    s_level << "Level: " << level;
    QString level_board = QString::fromStdString(s_level.str());
    painter.drawText(static_cast<int>(this->getPosition()->getXCoordinate()),
                     static_cast<int>(this->getPosition()->getYCoordinate()+20),
                     level_board);

    std::stringstream s_life;
    s_life << "Life: " << life;
    QString life_board = QString::fromStdString(s_life.str());
    painter.drawText(static_cast<int>(this->getPosition()->getXCoordinate()),
                     static_cast<int>(this->getPosition()->getYCoordinate()+40),
                     life_board);

}

