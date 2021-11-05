#ifndef MINE_H
#define MINE_H

#include "building.h"

class Mine : public Building {

public:

    Mine(string, int, int);

    //PRE:
    //POS:
    int quantity_provides_materials();
};

#endif // MINE_H
