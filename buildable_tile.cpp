#include "buildable_tile.h"

BuildableTile::BuildableTile() {
    building_contained = 0;
}

void BuildableTile::show() {
    if (tile_empty())
        cout << "Cansillero consultado es construible y se encuentra " << state_of_tile() << endl;
    else
        cout << "Cansillero consultado es construible y se encuentra " << state_of_tile()
             << ", contiene el edificio: " << building_contained->get_type() << endl;
}

void BuildableTile::add_value(Building* building) {

    building_contained = building;

}

bool BuildableTile::tile_not_empty(){

  return building_contained != 0;

}

string BuildableTile::state_of_tile(){

  if(tile_empty())
    return "vacio";

  return "ocupado";

}

string BuildableTile::get_value(){

  return building_contained->get_type();

}

string BuildableTile::get_tile_class() {

  return BUILDABLE;

}
