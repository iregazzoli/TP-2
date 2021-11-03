#include "building_handler.h"

BuildingHandler::BuildingHandler() {

  buildings = new List<Building>;

}

void BuildingHandler::add_building(string building_type, int x_coordinate, int y_coordinate) {

  Building* new_building = new Building(building_type, x_coordinate, y_coordinate);
  buildings->add_node(new_building);

}

bool BuildingHandler::demolish_building(int x_coordinate, int y_coordinate) {

  buildings->reset_current_node();

  bool building_demolished = false;

  while (buildings->get_current_value() != 0 && building_demolished == false) {

    if (buildings->get_current_value()->get_x_coordinate() == x_coordinate &&
         buildings->get_current_value()->get_y_coordinate() == y_coordinate) {

        buildings->delete_current_node();

        building_demolished = true;

    }

    buildings->next_node();

  }

  buildings->reset_current_node();

  return building_demolished;

}

// int BuildingHandler::get_building_built_amount(string building_type_to_count){
//
//   buildings->reset_current_node();
//
//   int building_amount = 0;
//
//   while(buildings->get_current_value() != 0){
//
//     if(buildings->get_current_value()->get_type() == building_type_to_count)
//       building_amount++;
//
//     buildings->next_node();
//
//   }
//
//   return building_amount;
//
// }

void BuildingHandler::show_building(string building_type, int amount_built){

  buildings->reset_current_node();
  string coordinates = "";

  while(buildings->get_current_value() != 0){

    if(buildings->get_current_value()->get_type() == building_type){
      coordinates = coordinates + "(" + to_string(buildings->get_current_value()->get_x_coordinate())
                    + ", " + to_string(buildings->get_current_value()->get_y_coordinate())
                    + ")";

    }

    buildings->next_node();

  }

  std::cout << left << setw(WIDTH) << "Amount of: " << BOLD_GREEN
    << setw(WIDTH) << building_type << DEFAULT_COLOR <<
     setw(WIDTH) << " is: " << BOLD_BLUE << amount_built << DEFAULT_COLOR <<
      " in coordinates" << BOLD_YELLOW << setw(WIDTH) << coordinates << '\n';

}


BuildingHandler::~BuildingHandler(){

  buildings->reset_current_node();

  delete buildings;

}
