#ifndef STAGE3TESTFACTORY_H
#define STAGE3TESTFACTORY_H

#include "gamefactory.h"

class Stage3TestFactory : public GameFactory{
public:
    Stage3TestFactory() = default;
    ~Stage3TestFactory() override = default;

    GameDialog* createGame() override;
};

#endif // STAGE3TESTFACTORY_H
