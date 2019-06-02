#pragma once

// Responsible for storing the game state of the current game, independently of rendering.

#include <string>
#include <vector>

class Background;
class Entity;
class Player;

class GameState {

public:
    GameState();
    virtual ~GameState();

    Entity* getRootEntity();
    void setRootEntity(Entity* root);

    Entity* findEntityByName(const std::string& name);
    std::vector<Entity*> findEntitiesByNameContains(const std::string& string);

    Background* getBackground();
    void setBackground(Background* bg);

    Player* getPlayer();
    void setPlayer(Player* player);

    virtual void update(bool paused);
    bool getPlayerColliding() {return player_colliding; }

    // Stage 3 exclusive
    void setPlayerColliding(bool b) { player_colliding = b;}

    virtual bool getGameOver() { return false; }
    virtual unsigned int getLevel() { return 1; }
    virtual unsigned int getLife() { return 1; }
    virtual void setLife(unsigned int life) { return; }

protected:
    virtual void checkCollisions();

private:
    Entity* findEntityByNameRecursive(const std::string& name, Entity* root);
    void findEntitiesByNameContainsRecursive(const std::string& string, Entity* root, std::vector<Entity*>& list);

    Player* player;
    Background* background;
    Entity* root_entity;
    bool player_colliding;
};

