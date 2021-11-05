#ifndef PASSABLE_TILE_H
#define PASSABLE_TILE_H

#include "tile.h"

class PassableTile : public Tile {
private:
    string material_contained;
    int material_amount;

public:
    PassableTile();
    void show();
    void add_value();
    void remove_material();
    bool tile_empty();
    string state_of_tile();

    string get_tile_class();

};

#endif // PASSABLE_TILE_H
