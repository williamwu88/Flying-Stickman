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
#include "obstacleiterable.h"
#include "obstacleiterator.h"
#include <sstream>
#include <iostream>
#include <unistd.h>

GameStateStage3::GameStateStage3()
    : GameState(),
      giant_explode(":/sound/ding-sound-effect.wav"),
      lose_life(":/sound/game-over.wav"),
      victory(":/sound/victory.wav")
{
    default_velocity = Config::config()->getStickman()->getVelocity();
    current_velocity = default_velocity;
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
                        player_collided = true;
                    }else{
                        if(Config::config()->getStickman()->getSize() == "giant"){
                            giant_explode.play();
                            entity->onCollision(this->getPlayer());
                            std::cout << "We are here" << std::endl;
                        }else{
                            e = entity;
                            lose_life.play();
                            life--;
                            std::cout << "Life now is :" << life << std::endl;
                            current_velocity = Config::config()->getStickman()->getVelocity();
                            player_collided = true;
                        }
                    }
                }else if(entity->getName().compare("victory_flag") == 0){
                    if(e == entity){

                    }else{
                        e = entity;
                        victory.play();
                        level++;
                        Stickman* stickman = Config::config()->getStickman();
                        if(stickman->getVelocity() >= 30){

                        }else{
                            stickman->changeVelocity(stickman->getVelocity()+static_cast<double>(level));
                            std::cout << "Velocity " << stickman->getVelocity() << std::endl;
                            current_velocity = stickman->getVelocity();
                        }
                        victory_flag_collided = true;
                    }
                }
            }
        }
        setPlayerColliding(player_collided);
    }
}



void GameStateStage3::update(bool paused) {
    checkCollisions();
    double deltaTimeMilliseconds = 32; // Comes from hard coded timer interval value in Stage1Game.

    Stickman* stickman = Config::config()->getStickman();

    if(life == 0){
        gameover = true;
        setPlayerColliding(true);
        stickman->changeVelocity(default_velocity);
        level = 1;

    }else if(victory_flag_collided){
        stickman->changeVelocity(0);
        if(victory.isFinished()){
            stickman->changeVelocity(current_velocity);
            std::cout << "Now stickman velocity is " << current_velocity << std::endl;
            resetScene();
            victory_flag_collided = false;
        }else{
            setPlayerColliding(true);
        }

    }
    else if(getPlayerColliding()){
        stickman->changeVelocity(0);
        if(lose_life.isFinished()){
            stickman->changeVelocity(current_velocity);
            std::cout << "Now stickman velocity is " << current_velocity << std::endl;
            resetScene();
        }else{
            setPlayerColliding(true);
        }
    }else{
        getRootEntity()->update(paused || getPlayerColliding(), deltaTimeMilliseconds);
    }

}

void GameStateStage3::resetScene(){
    // Reset scene here
    unsigned int world_height = Config::config()->getWorldHeight();
    unsigned int world_width = Config::config()->getWorldWidth();
    EmptyEntity* root = new EmptyEntity(new Coordinate(0, 0, world_height, world_width), "root");
    ExtendedConfig config(*Config::config());
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
                                               loop*level, "victory_flag");
    root->addChild(victoryflag);

    setRootEntity(root);
}

