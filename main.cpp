#include <iostream>
#include <fstream>
#include "city.h"
#include "building.h"
#include <cctype>
#include <cstring>

using namespace std;

//---------------------------Loading from txt files-----------------------------

bool load_materials(City* city) {

  ifstream file;
  file.open(MATERIAL_FILE_ROUTE);

  if (!file) {

    cout << BOLD_RED << "ERROR!:" <<  DEFAULT_COLOR << " Could not find file: "
                                     "'materiales.txt', ending program" << endl;
    return false;

  }

  else{

    if (file.peek() == EOF) {

      // (Se que el enunciado me asegura que el archivo no va a estar vacio,
      //   pero nunca esta de mas checekar)
      cout << BOLD_RED << "ERROR!: " <<  DEFAULT_COLOR << "file: "
                            "'materiales.txt' is empty, ending program" << endl;
      return false;

    }

    string current_material;

    //quantity_of_material is a string because function getline takes a -
    //-string& str as second argument.
    string quantity_of_material;

    while ((file.peek() != EOF)) {

      getline(file, current_material, ' ');
      getline(file, quantity_of_material, '\n');

      city->add_material(current_material, stoi(quantity_of_material));

    }

  }

  file.close();
  return true;

}


bool load_buildings(City* city) {

  ifstream file;
  file.open(BUILDING_FILE_ROUTE);

  if (!file) {

    // (Se que el enunciado me asegura que el archivo no va a estar vacio,
    //   pero nunca esta de mas checekar)
    cout << BOLD_RED << "ERROR!: " << DEFAULT_COLOR << "Could not find file: "
                                      "'edificios.txt', ending program" << endl;

    return false;

  }

  else {

    if (file.peek() == EOF) {

      cout << BOLD_RED << "ERROR!: " << DEFAULT_COLOR << "file 'edificios.txt'"
                                            " is empty, ending program" << endl;

      return false;

    }

    string building_type;
    //Again getline accepts only strings so thats why here everything is not an int
    string stone_cost;
    string wood_cost;
    string steel_cost;
    string building_quantity;
    string max_building_quantity;

    while ((file.peek() != EOF)) {

      getline(file, building_type, ' ');
      getline(file, stone_cost, ' ');
      getline(file, wood_cost, ' ');
      getline(file, steel_cost, ' ');
      getline(file, building_quantity, ' ');
      getline(file, max_building_quantity, '\n');

      //Creates the bulding struct in the record of the City
      city->add_building(building_type, stoi(stone_cost), stoi(wood_cost),
                          stoi(steel_cost), stoi(max_building_quantity));

      //Creates the Building object
      city->add_building(building_type, stoi(building_quantity), true);

    }
  }

  file.close();
  return true;

}

void save_data(City* city) {

  fstream material_file;
  material_file.open(MATERIAL_FILE_ROUTE, ios::out);

  if (material_file.is_open()) {

    material_file << city->materials_data_to_string();

    material_file.close();

  }

  fstream building_file;
  building_file.open(BUILDING_FILE_ROUTE, ios::out);

  if (building_file.is_open()) {

    building_file << city->building_data_to_string();

    building_file.close();

  }

}

//------------------------------Menu Options------------------------------------

void build(City* city) {

  system (CLR_SCREEN);
  string building_to_add;
  std::cout << "Enter the type of building you wish to build: ";
  std::cin >> building_to_add;
  city->add_building(building_to_add, 1, false);

}


void demolish(City* city) {

  system (CLR_SCREEN);
  string building_to_demolish;
  std::cout << "Enter the type of building you wish to demolish: ";
  std::cin >> building_to_demolish;
  city->demolish_building(building_to_demolish);

}


void how_do_you_turn_this_on() {

  system (CLR_SCREEN);
  string problematic_line_1_part_1 = R"(/`-')";
  string problematic_line_1_part_2 = R"(( )         ( ))";
  string problematic_line_1_part_3 = R"( /`-'\)";

  string problematic_line_2_part_1 = R"(|   |)";
  string problematic_line_2_part_2 = R"(---\_Cobra_/---)";
  string problematic_line_2_part_3 = R"(|   |)";

  std::cout << '\n';
  std::cout << "                  BRRRRRRRRRRRRRRRRRRRRRR" << '\n';
  std::cout << "        _________" << '\n';
  std::cout << "       |         |" << '\n';
  std::cout << BOLD_BLUE << " _o_  _";
  std::cout << DEFAULT_COLOR << "| " << BOLD_BLUE << "___=___" << DEFAULT_COLOR <<" |";
  std::cout << BOLD_BLUE << "_  _o_" << '\n';
  std::cout << problematic_line_1_part_1;
  std::cout << DEFAULT_COLOR << problematic_line_1_part_2;
  std::cout << BOLD_BLUE << problematic_line_1_part_3 << '\n';
  std::cout << BOLD_BLACK << "|   |-"<< BOLD_BLUE << "| ";
  std::cout << DEFAULT_COLOR << " ___*___ ";
  std::cout << BOLD_BLUE << " |" << BOLD_BLACK << "-|   |" << '\n';
  std::cout << "|   |" << BOLD_BLUE << " | ";
  std::cout << BOLD_BLACK << "(-+-+-+-)";
  std::cout << BOLD_BLUE << " |" << BOLD_BLACK <<" |   |" << '\n';
  std::cout << problematic_line_2_part_1;
  std::cout << DEFAULT_COLOR << problematic_line_2_part_2;
  std::cout << BOLD_BLACK << problematic_line_2_part_3 << '\n';
  std::cout << BOLD_BLACK << " ---                 ---" << DEFAULT_COLOR << '\n';

}


void show_menu() {

  std::cout << '\n';
  std::cout << "Welcome to " << BOLD_GREEN << "Andypolis Construction Menu"
                                  << DEFAULT_COLOR << ", options are: " << '\n';

  std::cout << BOLD_YELLOW << "[1]" << DEFAULT_COLOR << " List construction materials. ('1' or 'materials')" << '\n';
  std::cout << BOLD_YELLOW << "[2]" << DEFAULT_COLOR << " Build building by name. ('2' or 'build')" << '\n';
  std::cout << BOLD_YELLOW << "[3]" << DEFAULT_COLOR << " List the buildings built. ('3' or 'buildings')" << '\n';
  std::cout << BOLD_YELLOW << "[4]" << DEFAULT_COLOR << " List all buildings. ('4' or 'record')" << '\n';
  std::cout << BOLD_YELLOW << "[5]" << DEFAULT_COLOR << " Demolish a building by name. ('5' or 'demolish')" << '\n';
  std::cout << BOLD_YELLOW << "[6]" << DEFAULT_COLOR << " How do you turn this on. ('6' or 'how_do_you_turn_this_on')" << '\n';
  std::cout << BOLD_YELLOW << "[7]" << DEFAULT_COLOR << " Save and exit. ('7' or 'exit')" << '\n';
  return;

}


int main(){
  system (CLR_SCREEN);
  City andypolis;
  load_materials(&andypolis);
  load_buildings(&andypolis);

  string user_option;
  bool end_program = false;

  while (!end_program) {

    show_menu();

    std::cout << '\n' << "Please enter the option you want: ";
    std::cin >> user_option;

    if (user_option == "1" or user_option == "materials") {

      system (CLR_SCREEN);
      andypolis.show_materials();

    }

    else if (user_option == "2" or user_option == "build")
      build(&andypolis);

    else if (user_option == "3" or user_option == "buildings")
      andypolis.show_buildings();

    else if (user_option == "4" or user_option == "record")
      andypolis.show_record();

    else if (user_option == "5" or user_option == "demolish")
      demolish(&andypolis);

    else if (user_option == "6" or user_option == "how_do_you_turn_this_on")
      how_do_you_turn_this_on();

    else if (user_option == "7" or user_option == "exit"){

      save_data(&andypolis);
      std::cout << "Hope you enjoyed the program!" << '\n';
      end_program = true;

    }

    else {

      system (CLR_SCREEN);
      std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR
            << "Invalid option, please enter a valid input" << '\n';
    }

  }

  return 0;

}
