#ifndef STICKMANPLAYERSTAGE3_H
#define STICKMANPLAYERSTAGE3_H

#include "player.h"
#include "stickman.h"
#include "config.h"
#include "physicsbodystage3.h"
#include "obstacle.h"
#include "gamestatestage3.h"

#include <cmath>
#include <QSound>

class StickmanPlayerStage3 : public Player{
public:

    StickmanPlayerStage3(Coordinate* position, std::string name);
    ~StickmanPlayerStage3() override;

    // Override
    virtual void jump() override;


    void checkGroundCollision();
    void landed();

    virtual RectCollider* getCollider() override { return &collider; }

    virtual void onCollision(Entity* other) override;
    virtual void update(bool paused, double time_since_last_frame) override;
    virtual void render(QPainter &painter) override;

    // Stage 3 exclusive
//    void setLife(unsigned int number){ life = number; }
//    unsigned int getLife() { return life; }

    void increaseLevel() { level++; }
    unsigned int getLevel() { return level; }

    virtual double getYVelocity() override { return physics_body_stage3.getYVelocity(); };

private:
//    unsigned int life = 5;
    PhysicsBodyStage3 physics_body_stage3;

    RectCollider collider;

    double jump_height;
    double gravity;
    int jump_count;
    int max_jump_count = 2;

    int frame_number;
    int counter;

    // Stage 3
    unsigned int level;
    QSound sound;

};

#endif // STICKMANPLAYERSTAGE3_H
