#pragma once

#include "stickman.h"

class Config {

public:

    static Config *config() {

        static Config config_instance;

        return &config_instance;
    }

    virtual ~Config() = default;

    virtual void setupConfig();

    //Getter functions
    Stickman* getStickman() { return stickman; }
    unsigned int getWorldWidth() { return world_width; }
    unsigned int getWorldHeight() { return world_height; }
    int getBackgroundNumber() { return background_number; }

    //Setter functions
    void setWorldWidth(unsigned int width) { world_width = width; }
    void setWorldHeight(unsigned int height) { world_height = height; }
    void setBackgroundNumber(int number) { background_number = number; }
    void setStickman(Stickman *new_stickman) { stickman = new_stickman; }

private:

    // Private so that it can not be called
    Config() = default;

    unsigned int world_width = 0;
    unsigned int world_height = 0;
    int background_number = 0;
    Stickman *stickman = nullptr;
};

