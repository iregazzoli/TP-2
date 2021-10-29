#include "passable_tile.h"

Passable_tile::Passable_tile () {
    tile_empty = true;
    material_contained = "";
    material_amount = 0;
}

void Passable_tile::show() {
    if (tile_empty)
        cout << "Cansillero consultado es transitable y se encuentra " << state_of_tile() << endl;
    else
        cout << "Cansillero consultado es transitable y se encuentra " << state_of_tile()
             << ", contiene: " << material_contained << endl;
}

void Passable_tile::add_material(string material) {
    material_contained = material;
    material_amount = 1;
    tile_empty = false;
}

void Passable_tile::remove_material() {
    tile_empty = true;
    material_contained = "";
    material_amount = 0;
}
