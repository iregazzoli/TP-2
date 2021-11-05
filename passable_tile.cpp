#include "passable_tile.h"

PassableTile::PassableTile () {
    material_contained = "";
    material_amount = 0;
}

void PassableTile::show() {
    if (tile_empty())
        cout << "Cansillero consultado es transitable y se encuentra " << state_of_tile() << endl;
    else
        cout << "Cansillero consultado es transitable y se encuentra " << state_of_tile()
             << ", contiene: " << material_contained << endl;
}

void PassableTile::remove_material() {

    material_contained = "";
    material_amount = 0;

}

bool PassableTile::tile_empty(){

  if(material_contained == "")
    return true;

  return false;

}

string PassableTile::state_of_tile(){

  if(tile_empty())
    return "vacio";

  return "ocupado";

}

string PassableTile::get_tile_class() {

  return PASSABLE;

}
