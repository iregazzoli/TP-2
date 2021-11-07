#include "passable_tile.h"

PassableTile::PassableTile () {
    material_contained = "";
    material_amount = 0;
}

void PassableTile::show() {
  cout << "Consulted tile is " << PASSABLE << "and is ";


   if (tile_empty())
       cout << state_of_tile() << endl;
   else
       cout << state_of_tile()
              << ", contains: " << material_contained << endl;
 
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
    return EMPTY;

  return OCCUPIED;

}

string PassableTile::get_tile_class() {

  return PASSABLE;

}
