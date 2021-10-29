#ifndef TILE_H
#define TILE_H
#include <fstream>
#include <iostream>
using namespace std;

class Tile {
protected:
    bool tile_empty;

public:

    Tile(){};

    //PRE:
    //POST:
    virtual void show() = 0;

    string state_of_tile();
};

#endif
