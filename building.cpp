#include "building.h"

Building::Building(string type){
  building_type = type;
}

void Building::set_type(string new_type){
  building_type = new_type;
}
string Building::get_type(){
  return building_type;
}
