#ifndef EXTENDEDCONFIGSTAGE3_H
#define EXTENDEDCONFIGSTAGE3_H

#include "extendedconfig.h"

class ExtendedConfigStage3 : public ExtendedConfig {
public:
    ExtendedConfigStage3(Config& config);
//    ~ExtendedConfigStage3() override;

    //Getter functions
    int getLevel(){ return level; }
    int getLife(){ return life; }

    //Setter functions
    void setLevel(int number) { level = number; }
    void setLife(int number) { life = number; }

protected:
    void setupStage3Config();

private:
    int level = 1;
    int life = 5;
};

#endif // EXTENDEDCONFIGSTAGE3_H
