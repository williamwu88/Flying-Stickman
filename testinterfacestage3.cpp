#include "testinterfacestage3.h"

#include "gamestate.h"
#include "gamedialog.h"

TestInterfaceStage3::TestInterfaceStage3(Stage3TestFactory *factory)
    : factory(factory)
{}

TestInterfaceStage3::~TestInterfaceStage3(){
    delete state;
}

void TestInterfaceStage3::startStage3TestInterface(){
    auto game_dialog = std::unique_ptr<GameDialog>(factory->createGame());
    game_dialog->setModal(true);
    game_dialog->setWindowTitle("Testing");
    game_dialog->exec();
}

