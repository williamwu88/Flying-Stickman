#ifndef STICKMANPLAYERSTAGE3_H
#define STICKMANPLAYERSTAGE3_H

#include "stickmanplayer.h"

class StickmanPlayerStage3 : public StickmanPlayer{
public:

    StickmanPlayerStage3(Coordinate* position, std::string name);

    // Override
//    virtual void onCollision(Entity* other) override;


    // Stage 3 exclusive
    void setLife(unsigned int number){ life = number; }

    unsigned int getLife() { return life; }

private:
    unsigned int life = 5;
};

#endif // STICKMANPLAYERSTAGE3_H
