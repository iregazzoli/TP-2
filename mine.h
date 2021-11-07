#ifndef MINE_H
#define MINE_H

#include "building.h"

class Mine : public Building {

public:

    Mine(string, string, int, int);

    //PRE:
    //POS:
    int produce_material();
};

#endif // MINE_H
