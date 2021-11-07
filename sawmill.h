#ifndef SAWMILL_H
#define SAWMILL_H

#include "building.h"

class Sawmill: public Building {

public:

    Sawmill(string, string, int, int);

    //PRE:
    //POS:
    int produce_material();

};

#endif // SAWMILL_H
