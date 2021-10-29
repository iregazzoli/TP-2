#ifndef BUILDABLE_TILE_H
#define BUILDABLE_TILE_H

#include "tile.h"

class Buildable_tile : public Tile {
private:
    string type_building_contained;

public:
    Buildable_tile();
    void show();
    void build(string building);
};

#endif //
