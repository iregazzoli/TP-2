#include "buildable_tile.h"

BuildableTile::BuildableTile() {
    building_contained = 0;
}

void BuildableTile::show() {
    if (tile_empty())
        cout << "Cansillero consultado es construible y se encuentra " << state_of_tile() << endl;
    else
        cout << "Cansillero consultado es construible y se encuentra " << state_of_tile()
             << ", contiene el edificio: " << building_contained << endl;
}

void BuildableTile::build(Building building) {

    building_contained = &building;

}

bool BuildableTile::tile_empty(){

  if(building_contained == 0)
    return true;

  return false;

}

string BuildableTile::state_of_tile(){

  if(tile_empty())
    return "vacio";

  return "ocupado";

}
