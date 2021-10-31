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
    void build(Building building);
    bool tile_empty();
    string state_of_tile();
};

#endif //
