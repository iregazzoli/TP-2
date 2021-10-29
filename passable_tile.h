#ifndef PASSABLE_TILE_H
#define PASSABLE_TILE_H

#include "tile.h"

class Passable_tile : public Tile {
private:
    string material_contained;
    int material_amount;

public:
    Passable_tile();
    void show();
    void add_material(string material);
    void remove_material();
};

#endif // PASSABLE_TILE_H
