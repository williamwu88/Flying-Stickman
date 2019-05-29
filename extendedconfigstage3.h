#ifndef EXTENDEDCONFIGSTAGE3_H
#define EXTENDEDCONFIGSTAGE3_H

#include "extendedconfig.h"

class ExtendedConfigStage3 : public ExtendedConfig {
public:
    ExtendedConfigStage3(Config& config);
//    ~ExtendedConfigStage3() override;

    //Getter functions
    int getLevel(){ return level; }

    //Setter functions
    void setLevel(int number) { level = number; }

protected:
    void setupStage3Config();

private:
    int level = 1;
};

#endif // EXTENDEDCONFIGSTAGE3_H
