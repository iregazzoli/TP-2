#ifndef INACCESIBLE_TILE_H
#define INACCESIBLE_TILE_H

#include "tile.h"

class InaccesibleTile : public Tile {

public:
    InaccesibleTile();
    void show();
    string get_tile_class();
    void add_value();
};

#endif // INACCESIBLE_TILE_H
