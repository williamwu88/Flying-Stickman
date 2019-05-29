#include "gamestatestage3.h"

#include "background.h"
#include "entity.h"
#include "player.h"
#include "rectcollider.h"

#include <iostream>

GameStateStage3::GameStateStage3()
    : GameState(), victory(false)
{}

std::string GameStateStage3::checkCollisionObject() {

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
                return entity->getName();
            }
        }
    }

    return "";
}

void GameStateStage3::checkCollisionStatus(){
    checkCollisions();
    if(this->getPlayerColliding()){
        std::string name = checkCollisionObject();
        if(name.compare("victory_flag") == 0){
            victory = true;
        }else if(name.compare(0, 7, "obstacle") == 0){

        }

    }
}



//void GameStateStage3::checkCollisions() {
//    bool player_collided = false;
//    for (auto* entity : findEntitiesByNameContains("")) {
//        // Check collisions with player
//        RectCollider* p_col = getPlayer()->getCollider();
//        RectCollider* o_col = entity->getCollider();
//        if (p_col != nullptr && o_col != nullptr) {
//            if (p_col->checkCollision(*o_col)) {
//                // Print which object collide with
//                getPlayer()->onCollision(entity);

//                entity->onCollision(getPlayer());

//                if(entity->getName().compare("victory_flag") == 0){
//                    victory = true;
//                }
//                player_collided = true;
//            }
//        }
//    }
//    player_colliding = player_collided;
//}

//void GameStateStage3::update(bool paused) {
//    checkCollisions();
//    double deltaTimeMilliseconds = 32; // Comes from hard coded timer interval value in Stage1Game.

//    if(victory){
//        std::cout << "victory" << std::endl;
//    }
//    getRootEntity()->update(paused || player_colliding, deltaTimeMilliseconds);
//    if (getPlayer() != nullptr) {
//        getPlayer()->update(paused, deltaTimeMilliseconds);
//    }
//}


