#ifndef INACCESIBLE_TILE_H
#define INACCESIBLE_TILE_H

#include "tile.h"

class InaccesibleTile : public Tile {

public:


    //PRE:-
    //POS: Created a InaccesibleTile object.
    InaccesibleTile();

    //PRE:-
    //POS: Informs on screen what type of tile it is.
    void show();

    //PRE:-
    //POS: Returns what is a 'INACCESIBLE' tile.
    string get_tile_class();

};

#endif // INACCESIBLE_TILE_H
