#include "record.h"

Record::Record() {

  record = new List<Building_record>;

}

void Record::add_building(string building_type, int stone_cost, int wood_cost,
                           int steel_cost, int max_building_quantity) {

    Building_record* new_building = new Building_record{building_type,stone_cost,
                                  wood_cost, steel_cost, max_building_quantity};

    record->add_node(new_building);

}

void Record::show_record() {

  record->reset_current_node();

  while(record->get_current_value() != 0){

    std::cout << "name: " << record->get_current_value()->building_type << '\n';
    std::cout << "stone: " << record->get_current_value()->stone_cost << '\n';
    std::cout << "wood: " << record->get_current_value()->wood_cost << '\n';
    std::cout << "steel: " << record->get_current_value()->steel_cost << '\n';
    std::cout << "max_quantity: " << record->get_current_value()->max_quantity << '\n';
    std::cout << '\n';

    record->next_node();

  }

  record->reset_current_node();

}

string Record::building_data_to_string() {

  record->reset_current_node();

  string building_data;

  while (record->get_current_value() != 0) {

    building_data = building_data + record->get_current_value()->building_type + " ";
    building_data = building_data + to_string(record->get_current_value()->stone_cost) + " ";
    building_data = building_data + to_string(record->get_current_value()->wood_cost) + " ";
    building_data = building_data + to_string(record->get_current_value()->steel_cost) + " ";
    building_data = building_data + to_string(record->get_current_value()->max_quantity) + "\n";

    record->next_node();
  }

  record->reset_current_node();

  return building_data;

}

string Record::get_current_building_type() {

  string building_type;

  building_type = record->get_current_value()->building_type;

  record->next_node();

  return building_type;

}

Record::~Record(){

  record->reset_current_node();

  delete record;

}
