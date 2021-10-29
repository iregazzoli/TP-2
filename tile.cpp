#include "tile.h"

string Tile::state_of_tile() {
    if (tile_empty)
        return "vacio";

    return "ocupado";
}
