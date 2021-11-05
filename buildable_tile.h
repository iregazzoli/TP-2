#ifndef BUILDABLE_TILE_H
#define BUILDABLE_TILE_H

#include "tile.h"
#include "building.h"

class BuildableTile : public Tile {
private:
    Building* building_contained;

public:
    BuildableTile();
    void show();
    void add_building(Building* building);
    void remove_building();
    bool tile_empty();
    string state_of_tile();
    string get_value();

    string get_tile_class();

};

#endif //
