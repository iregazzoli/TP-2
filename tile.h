#ifndef TILE_H
#define TILE_H
#include <fstream>
#include <iostream>
using namespace std;

class Tile {

public:

    Tile(){};

    //PRE:
    //POST:
    virtual void show() = 0;

    virtual bool tile_empty();

};

#endif
