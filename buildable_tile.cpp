#include "buildable_tile.h"

BuildableTile::BuildableTile() {
    building_contained = 0;
}

void BuildableTile::show() {
  cout << "Consulted tile is " << BUILDABLE << " and is ";

  if (tile_empty())
   cout << BOLD_GREEN << state_of_tile() << DEFAULT_COLOR << '\n';

  else
    if(building_contained->get_type() == POWER_PLANT)
      cout << BOLD_RED << state_of_tile() << DEFAULT_COLOR << ", contains building: " << BOLD_BLUE << "Planta eléctrica" << endl;

    else
      cout << BOLD_RED << state_of_tile() << DEFAULT_COLOR << ", contains building: " << BOLD_BLUE << building_contained->get_type() << endl;

}

void BuildableTile::add_building(Building* building) {

    building_contained = building;

}

void BuildableTile::remove_building() {

  building_contained = 0;

}

bool BuildableTile::tile_empty(){

  return building_contained == 0;

}

string BuildableTile::state_of_tile(){

  if(tile_empty())
    return EMPTY;

  return OCCUPIED;

}

string BuildableTile::get_value(){

  return building_contained->get_type();

}

string BuildableTile::get_tile_class() {

  return BUILDABLE;

}
