#include "scoreboard.h"

#include "coordinate.h"
#include <iostream>
#include <sstream>

ScoreBoard::ScoreBoard(Coordinate *position, std::string name)
    : Text(position, name){}

void ScoreBoard::update(bool paused, double time_since_last_frame){

    if (!paused) {
        setScore(current_score+time_since_last_frame);
    }

}

void ScoreBoard::render(QPainter &painter){
    std::stringstream stream;
    stream << "Score: " << current_score;

    QString board = QString::fromStdString(stream.str());

    painter.drawText(static_cast<int>(this->getPosition()->getXCoordinate()),
                     static_cast<int>(this->getPosition()->getYCoordinate()),
                     board);
}

