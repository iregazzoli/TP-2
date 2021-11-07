#ifndef FACTORY_H
#define FACTORY_H

#include "building.h"

class Factory : public Building {

public:

    Factory(string, string, int, int);

    //PRE:
    //POS:
    int produce_material();
};

#endif // FACTORY_H
