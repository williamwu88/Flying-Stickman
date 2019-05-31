#include "stage3gamestatefactory.h"
#include "stage3game.h"
#include "stickmanplayerstage3.h"
#include "obstacle.h"
#include "extendedconfig.h"
#include "emptyentity.h"
#include "victoryflag.h"
#include "scoreboard.h"
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

    // Will CHANGE this!
    ExtendedConfig config(*Config::config());
    // Load obstacle data
    std::vector<ObstacleConfig*> obstacle_data = config.getObstacleData();

    // Calculate when to loop the obstacles
    double loop = world_width;
    for (auto* obstacleConfig : obstacle_data){
        obstacleConfig->offset_x += std::rand() % 100;
        loop += obstacleConfig->offset_x;
    }

    // Create obstacles
    double previous_x = world_width;
    int count = 0;
    int lastObstacleWidth = 0;

    for (auto* obstacleConfig : obstacle_data){
        previous_x = previous_x + obstacleConfig->offset_x;
        std::stringstream name;
        name << "obstacle_" << count;
        Coordinate* obs_pos = new Coordinate(previous_x, obstacleConfig->position_y, world_height, world_width);
        Obstacle* obs = new Obstacle(obs_pos, obstacleConfig->width, obstacleConfig->height,
                                     -Config::config()->getStickman()->getVelocity(), loop,
                                     QColor(std::rand() % 255, std::rand() % 255, std::rand() % 255), name.str());
        root->addChild(obs);

        lastObstacleWidth = obstacleConfig->width;
        count++;
    }

    // Create victory flag
    previous_x += lastObstacleWidth;
    previous_x += 400;
    VictoryFlag *victoryflag = new VictoryFlag(new Coordinate(previous_x, 100, world_height, world_width),
                                               100, world_height,
                                               -Config::config()->getStickman()->getVelocity(),
                                               loop, "victory_flag");
    root->addChild(victoryflag);
    count++;

    // Create entity tree
    state->setRootEntity(root);
    state->setBackground(background);
    state->setPlayer(player);

    return state;
}
