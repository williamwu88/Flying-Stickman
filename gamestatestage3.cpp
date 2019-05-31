#include "gamestatestage3.h"

#include "background.h"
#include "coordinate.h"
#include "entity.h"
#include "player.h"
#include "rectcollider.h"
#include "obstacle.h"
#include "extendedconfig.h"
#include "emptyentity.h"
#include "victoryflag.h"
#include <sstream>
#include <iostream>
#include <unistd.h>

GameStateStage3::GameStateStage3()
    : GameState(),
      giant_explode(":/sound/ding-sound-effect.wav")
{
    default_velocity = Config::config()->getStickman()->getVelocity();
}

Entity* GameStateStage3::checkCollisionObject() {

    for (auto* entity : this->findEntitiesByNameContains("")) {
        // Check collisions with player
        RectCollider* p_col = getPlayer()->getCollider();
        RectCollider* o_col = entity->getCollider();
        if (p_col != nullptr && o_col != nullptr) {
            if (p_col->checkCollision(*o_col)) {
                // Print which object collide with
//                getPlayer()->onCollision(entity);
//                entity->onCollision(getPlayer());
                std::cout << "Player is colliding with" << entity->getName() << std::endl;
                return entity;
            }
        }
    }

    return nullptr;
}


void GameStateStage3::checkCollisions() {
    static Entity* e = nullptr;

    bool player_collided = false;
    for (auto* entity : findEntitiesByNameContains("")) {
        // Check collisions with player
        RectCollider* p_col = getPlayer()->getCollider();
        RectCollider* o_col = entity->getCollider();
        if (p_col != nullptr && o_col != nullptr) {
            if (p_col->checkCollision(*o_col)) {

                getPlayer()->onCollision(entity);
                entity->onCollision(getPlayer());
                if(entity->getName().compare(0, 8, "obstacle") == 0){
                    if(e == entity){

                    }else{
                        if(Config::config()->getStickman()->getSize() == "giant"){
                            giant_explode.play();
                        }else{
                            e = entity;
                            life--;
                            std::cout << "Life now is :" << life << std::endl;
                            player_collided = true;
                        }
                    }
                }else if(entity->getName().compare("victory_flag") == 0){
                    level++;
                    Stickman* stickman = Config::config()->getStickman();
                    if(stickman->getVelocity() >= 30){

                    }else{
                        stickman->changeVelocity(stickman->getVelocity()+static_cast<double>(level));
                        std::cout << "Velocity " << stickman->getVelocity() << std::endl;
                    }
                    victory_flag_collided = true;
                }
            }
        }
        setPlayerColliding(player_collided);
    }
}



void GameStateStage3::update(bool paused) {
    checkCollisions();
    double deltaTimeMilliseconds = 32; // Comes from hard coded timer interval value in Stage1Game.

    if(life == 0){
        gameover = true;
        setPlayerColliding(true);
        Stickman* stickman = Config::config()->getStickman();
        stickman->changeVelocity(default_velocity);
        level = 1;

    }else if(victory_flag_collided){
        sleep(1);
        resetScene();
        victory_flag_collided = false;
    }
    else if(getPlayerColliding()){
        sleep(1);
        resetScene();

    }else{
        getRootEntity()->update(paused || getPlayerColliding(), deltaTimeMilliseconds);
        if (getPlayer() != nullptr) {
            getPlayer()->update(paused, deltaTimeMilliseconds);
        }
    }

}

void GameStateStage3::resetScene(){
    // Reset scene here
    unsigned int world_height = Config::config()->getWorldHeight();
    unsigned int world_width = Config::config()->getWorldWidth();
    EmptyEntity* root = new EmptyEntity(new Coordinate(0, 0, world_height, world_width), "root");
    ExtendedConfig config(*Config::config());
    std::vector<ObstacleConfig*> obstacle_data = config.getObstacleData();

    // Calculate when to loop the obstacles
    double loop = world_width;
    for (auto* obstacleConfig : obstacle_data){
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
                                     QColor(obstacleConfig->colour_red, obstacleConfig->colour_green, obstacleConfig->colour_blue), name.str());
        root->addChild(obs);

        lastObstacleWidth = obstacleConfig->width;
        count++;
    }

    // Create victory flag
    previous_x += lastObstacleWidth;
    VictoryFlag *victoryflag = new VictoryFlag(new Coordinate(world_width, 100, world_height, world_width),
                                               100, world_height,
                                               -Config::config()->getStickman()->getVelocity(),
                                               loop*3, "victory_flag");
    root->addChild(victoryflag);
    count++;

    setRootEntity(root);
}

