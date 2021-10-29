#include "buildable_tile.h"

BuildableTile::BuildableTile() {
    tile_empty = true;
    type_building_contained = " ";
}

void BuildableTile::show() {
    if (tile_empty)
        cout << "Cansillero consultado es construible y se encuentra " << state_of_tile() << endl;
    else
        cout << "Cansillero consultado es construible y se encuentra " << state_of_tile()
             << ", contiene el edificio: " << type_building_contained << endl;
}

void BuildableTile::build(string building) {
    tile_empty = false;
    type_building_contained = building;
}
