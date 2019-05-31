#include "stage3gamestatefactory.h"
#include "stage3game.h"
#include "stickmanplayerstage3.h"
#include "obstacle.h"
//#include "extendedconfig.h"
#include "extendedconfigstage3.h"
#include "emptyentity.h"
#include "victoryflag.h"
#include "scoreboard.h"
#include "obstacleiterable.h"
#include "obstacleiterator.h"
#include <sstream>

GameState *Stage3GameStateFactory::createGameState(){
    GameStateStage3* state = new GameStateStage3();

    unsigned int world_height = Config::config()->getWorldHeight();
    unsigned int world_width = Config::config()->getWorldWidth();

    // Create background and player
    Background* background = new Background(Coordinate(0, world_height, world_height, world_width));
    StickmanPlayerStage3* player = new StickmanPlayerStage3(new Coordinate(Config::config()->getStickman()->getXPosition()- (Config::config()->getStickman()->getWidth()*0.5),
                                                0 + Config::config()->getStickman()->getHeight(),
                                                world_height,
                                                world_width),
                                                "stickman");
    Coordinate* pos = new Coordinate(0, 0, world_height, world_width);
    EmptyEntity* root = new EmptyEntity(pos, "root");

    // Read stage 3 config
    ExtendedConfigStage3 config(*Config::config());
    // Load obstacle data
    std::vector<ObstacleConfig*> obstacle_data = config.getObstacleData();

    // Calculate when to loop the obstacles, set random obstacle x coordinate
    double loop = world_width;
    for (auto* obstacleConfig : obstacle_data){
        obstacleConfig->offset_x += std::rand() % 100;
        loop += obstacleConfig->offset_x;
    }

    // Create obstacles
    double previous_x = world_width;

    ObstacleIterable obstacle_iterable(obstacle_data);
    Iterator *obstacle_iterator = obstacle_iterable.createIterator(loop);
    Obstacle* obs = nullptr;
    while(obstacle_iterator->hasNext()){
        obs = obstacle_iterator->getNext();
        root->addChild(obs);
    }

    // Create victory flag
    previous_x += world_width;
    VictoryFlag *victoryflag = new VictoryFlag(new Coordinate(world_width, 100, world_height, world_width),
                                               100, world_height,
                                               -Config::config()->getStickman()->getVelocity(),
                                               loop, "victory_flag");
    root->addChild(victoryflag);

    // Create entity tree
    state->setRootEntity(root);
    state->setBackground(background);
    state->setPlayer(player);
    state->setLife(config.getLife());

    return state;
}
