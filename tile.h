#ifndef TILE_H
#define TILE_H
#include <fstream>
#include <iostream>
#include "constants.h"
using namespace std;

class Tile {

public:

    Tile(){};

    //PRE:
    //POST:
    virtual void show() = 0;

    virtual bool tile_empty();

    virtual string get_value();

    virtual string get_tile_class() = 0;

};

#endif
