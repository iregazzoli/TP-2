#include "building_handler.h"

BuildingHandler::BuildingHandler() {

  buildings = new List<Building>;

}

void BuildingHandler::add_building(string building_type, int x_coordinate, int y_coordinate) {

  Building* new_building = 0;

  if(building_type == "fabrica")
    new_building = new Factory(building_type, x_coordinate, y_coordinate);

  if(building_type == "mina")
    new_building = new Mine(building_type, x_coordinate, y_coordinate);

  if(building_type == "obelisco")
    new_building = new Obelisk(building_type, x_coordinate, y_coordinate);

  if(building_type == "planta")
    new_building = new PowerPlant(building_type, x_coordinate, y_coordinate);

  if(building_type == "aserradero")
    new_building = new Sawmill(building_type, x_coordinate, y_coordinate);

  if(building_type == "escuela")
    new_building = new School(building_type, x_coordinate, y_coordinate);


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

int BuildingHandler::get_building_built_amount(string building_type_to_count){

  buildings->reset_current_node();

  int building_amount = 0;

  // std::cout << "entered here" << '\n';
  // std::cout << buildings->get_current_value() << '\n';

  while(buildings->get_current_value() != 0){

    // std::cout << building_type_to_count << " vs " << buildings->get_current_value()->get_type() << '\n';

    if(buildings->get_current_value()->get_type() == building_type_to_count)
      building_amount++;

    buildings->next_node();

  }

  return building_amount;

}

void BuildingHandler::show_building(string building_type, int amount_built){

  buildings->reset_current_node();
  string coordinates = "";
  string capitalized_building_type = capitalize_word(building_type);

  while(buildings->get_current_value() != 0){

    if(buildings->get_current_value()->get_type() == building_type){
      coordinates = coordinates + "(" + to_string(buildings->get_current_value()->get_x_coordinate())
                    + ", " + to_string(buildings->get_current_value()->get_y_coordinate())
                    + ") ";

    }

    buildings->next_node();

  }

  if(capitalized_building_type == "Planta")
    capitalized_building_type = "Planta eléctrica";

  std::cout << left << setw(WIDTH) << "Amount of: " << BOLD_GREEN <<
             capitalized_building_type  << "s" << DEFAULT_COLOR <<
              setw(WIDTH) << " is: " << BOLD_BLUE << amount_built << DEFAULT_COLOR <<
               " in coordinates: " << BOLD_YELLOW << setw(WIDTH) << coordinates <<  DEFAULT_COLOR <<'\n';

}

Building* BuildingHandler::get_building(string building_type, int x_coordinate, int y_coordinate) {

  while(buildings->get_current_value() != 0){

    if(buildings->get_current_value()->get_type() == building_type
       && buildings->get_current_value()->get_x_coordinate() == x_coordinate
       && buildings->get_current_value()->get_y_coordinate() == y_coordinate){

      return buildings->get_current_value();

    }

  }

  return 0;
}


BuildingHandler::~BuildingHandler(){

  delete buildings;

}
