#ifndef EXTENDEDCONFIGSTAGE3_H
#define EXTENDEDCONFIGSTAGE3_H

#include "extendedconfig.h"

class ExtendedConfigStage3 : public ExtendedConfig {
public:
    ExtendedConfigStage3(Config& config);
//    ~ExtendedConfigStage3() override;

    unsigned int getLife(){ return life; }
    void setLife(unsigned int number) { life = number; }

protected:
    void setupStage3Config();

private:
    unsigned int life = 5;
};

#endif // EXTENDEDCONFIGSTAGE3_H
