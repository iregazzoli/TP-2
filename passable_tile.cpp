#include "passable_tile.h"

PassableTile::PassableTile () {
    material_contained = "";
    material_amount = 0;
}

void PassableTile::show() {

  cout << "Consulted tile is " << BOLD_BLUE << PASSABLE << DEFAULT_COLOR << " and is ";

   if (tile_empty())
       cout << BOLD_GREEN << state_of_tile() << DEFAULT_COLOR << '\n';
   else
       cout << BOLD_RED << state_of_tile() << ", it contains: " <<
                BOLD_GREEN << material_contained << DEFAULT_COLOR << '\n';

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
