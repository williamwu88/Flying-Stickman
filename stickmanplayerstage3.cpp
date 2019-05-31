#include "stickmanplayerstage3.h"

#include "coordinate.h"
#include <sstream>
#include <QSound>

StickmanPlayerStage3::StickmanPlayerStage3(Coordinate* position, std::string name)
    : Player(position, name),
      physics_body_stage3(new Coordinate(0, 0, position->getFrameHeight(), position->getFrameWidth())),
      collider(RectCollider(new Coordinate(0, 0, position->getFrameHeight(), position->getFrameWidth()),
                            new Coordinate(0, 0, position->getFrameHeight(), position->getFrameWidth()))),
      jump_height(150),
      gravity(-9.8*200),
      jump_count(0),
      frame_number(1),
      counter(0),
      level(1),
      sound(":/sound/jump-sound.wav")
{
    physics_body_stage3.setYAcceleration(gravity);
}

StickmanPlayerStage3::~StickmanPlayerStage3(){

}

void StickmanPlayerStage3::jump() {

    if (Config::config()->getStickman()->getSize() == "large"){
        max_jump_count = 3;
    } else if (Config::config()->getStickman()->getSize() == "giant"){
        max_jump_count = 3;
    } else {
        max_jump_count = 2;
    }

    if (jump_count < max_jump_count) {
        jump_count += 1;
        physics_body_stage3.setYVelocity(std::sqrt(-2*gravity*jump_height));

        sound.play();
    }

}

void StickmanPlayerStage3::landed() {
    jump_count = 0;
    physics_body_stage3.setYVelocity(0);
}

void StickmanPlayerStage3::checkGroundCollision() {
    if (physics_body_stage3.getPos()->getYCoordinate() <= 0) {
        physics_body_stage3.getPos()->setYCoordinateToZero(0);
        landed();
    }
}

void StickmanPlayerStage3::onCollision(Entity *other){
    static Entity *e = nullptr;

    if(e != other){
        e = other;

        std::cout << other->getName() << std::endl;

    }else{

    }
}



void StickmanPlayerStage3::update(bool paused, double time_since_last_frame){
    // Physics updates
    physics_body_stage3.apply(time_since_last_frame/1000.0);

    checkGroundCollision();

    Stickman* stickman = Config::config()->getStickman();

    // Keep position coordinate and collider coordinates in sync with the Config
    this->getPosition()->setXCoordinateToZero(stickman->getXPosition() - (stickman->getWidth()*0.5));
    this->getPosition()->setYCoordinateToZero(stickman->getHeight() + physics_body_stage3.getPos()->getYCoordinate());
    this->collider.getV1()->setXCoordinateToZero(this->getPosition()->getXCoordinate());
    this->collider.getV1()->setYCoordinateToZero(this->getPosition()->getYCoordinate());
    this->collider.getV2()->setXCoordinateToZero(this->getPosition()->getXCoordinate() + stickman->getWidth());
    this->collider.getV2()->setYCoordinateToZero(this->getPosition()->getYCoordinate() - stickman->getHeight());

    //Used to slow down the animation
    if (counter == 2) {
        frame_number++;
        counter = 0;
    }

    //Once the frame is the last, reset
    if (frame_number > 9) {
        frame_number = 1;
    }

    //Only increment the counter if its not paused
    if (!paused) {
        counter++;
    }
}

void StickmanPlayerStage3::render(QPainter &painter) {
    QPixmap sprite = Config::config()->getStickman()->getPixmap(frame_number);
    painter.drawPixmap(this->getPosition()->getQtRenderingXCoordinate(),
                       this->getPosition()->getQtRenderingYCoordinate(),
                       Config::config()->getStickman()->getWidth(),
                       Config::config()->getStickman()->getHeight(),
                       sprite);
}
