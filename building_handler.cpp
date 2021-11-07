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

  while(buildings->get_current_value() != 0){

    if(buildings->get_current_value()->get_type() == building_type_to_count)
      building_amount++;

    buildings->next_node();

  }

  return building_amount;

}

void BuildingHandler::show_buildings(string building_type, int amount_built){

  buildings->reset_current_node();
  string coordinates = "";
  string capitalized_building_type = capitalize_word(building_type);
  int building_type_spacing = 17;

  while (buildings->get_current_value() != 0) {

    if(buildings->get_current_value()->get_type() == building_type){
      coordinates = coordinates + "(" + to_string(buildings->get_current_value()->get_x_coordinate())
                    + ", " + to_string(buildings->get_current_value()->get_y_coordinate())
                    + ") ";

    }

    buildings->next_node();

  }

  if (capitalized_building_type == "Planta") {

    capitalized_building_type = "Planta eléctrica";
    building_type_spacing = 18;

  }

  std::cout << left << setw(15) << "Amount of building: " << BOLD_GREEN <<
             setw(building_type_spacing) << capitalized_building_type  << DEFAULT_COLOR <<
              setw(4) << "is: " << BOLD_BLUE << amount_built << DEFAULT_COLOR << setw(4) <<
              " in coordinates: " << BOLD_YELLOW << setw(WIDTH) << coordinates <<  DEFAULT_COLOR <<'\n';

}

Building* BuildingHandler::get_building(string building_type, int x_coordinate, int y_coordinate) {

  while (buildings->get_current_value() != 0) {

    if (buildings->get_current_value()->get_type() == building_type
       && buildings->get_current_value()->get_x_coordinate() == x_coordinate
       && buildings->get_current_value()->get_y_coordinate() == y_coordinate){

      return buildings->get_current_value();

    }

  }

  return 0;
}

string BuildingHandler::building_data_to_string() {

  buildings->reset_current_node();

  string building_data;

  while (buildings->get_current_value() != 0) {

    building_data = building_data + buildings->get_current_value()->get_type() + " ";

    if(buildings->get_current_value()->get_type() == POWER_PLANT)
      building_data = building_data + "electrica ";

    building_data = building_data + "(";
    building_data = building_data + to_string(buildings->get_current_value()->get_x_coordinate()) + ", ";
    building_data = building_data + to_string(buildings->get_current_value()->get_y_coordinate()) + ") " + '\n';

    buildings->next_node();

  }

  buildings->reset_current_node();

  return building_data;

}

BuildingHandler::~BuildingHandler(){

  delete buildings;

}
