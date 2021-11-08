#ifndef PASSABLE_TILE_H
#define PASSABLE_TILE_H

#include "tile.h"
#include "material.h"

class PassableTile : public Tile {
private:
    Material* material_contained;


public:
    PassableTile();

    ~PassableTile();

    void add_material(Material* material);

    void show();

    void add_value();

    void remove_material();

    bool tile_empty();

    string state_of_tile();

    string get_tile_class();

};

#endif // PASSABLE_TILE_H
