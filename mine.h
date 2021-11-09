#ifndef MINE_H
#define MINE_H

#include "building.h"

class Mine : public Building {

public:

    //PRE:-
    //POS: Created Mine object.
    Mine(string, string, int, int);

    //PRE:-
    //POS: Returns amount of material mine produces.
    int produce_material();
};

#endif // MINE_H
