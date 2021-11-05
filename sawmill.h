#ifndef SAWMILL_H
#define SAWMILL_H

#include "building.h"

class Sawmill: public Building {

public:

    Sawmill(string, int, int);

    //PRE:
    //POS:
    int quantity_provides_materials();

};

#endif // SAWMILL_H
