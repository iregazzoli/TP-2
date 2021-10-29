#ifndef BUILDABLE_TILE_H
#define BUILDABLE_TILE_H

#include "tile.h"

class BuildableTile : public Tile {
private:
    string type_building_contained;

public:
    BuildableTile();
    void show();
    void build(string building);
};

#endif //
