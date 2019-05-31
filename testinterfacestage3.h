#ifndef TESTINTERFACESTAGE3_H
#define TESTINTERFACESTAGE3_H

#include "stage3gamefactory.h"
#include "stage3testfactory.h"
#include "gamestatestage3.h"
#include "obstacle.h"

class TestInterfaceStage3 {
public:
    TestInterfaceStage3(Stage3TestFactory *factory);
    virtual ~TestInterfaceStage3();

protected:
    Stage3TestFactory* factory;
    GameState* state;
    bool paused;
};

#endif // TESTINTERFACESTAGE3_H
