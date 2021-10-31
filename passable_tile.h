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
    void add_material(string material);
    void remove_material();
    bool tile_empty();
    string state_of_tile();
};

#endif // PASSABLE_TILE_H
