#include "passable_tile.h"

PassableTile::PassableTile () {
    tile_empty = true;
    material_contained = "";
    material_amount = 0;
}

void PassableTile::show() {
    if (tile_empty)
        cout << "Cansillero consultado es transitable y se encuentra " << state_of_tile() << endl;
    else
        cout << "Cansillero consultado es transitable y se encuentra " << state_of_tile()
             << ", contiene: " << material_contained << endl;
}

void PassableTile::add_material(string material) {
    material_contained = material;
    material_amount = 1;
    tile_empty = false;
}

void PassableTile::remove_material() {
    tile_empty = true;
    material_contained = "";
    material_amount = 0;
}
