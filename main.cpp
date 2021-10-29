#include "menu.h"
#include "inaccesible_tile.h"
#include "buildable_tile.h"
#include "passable_tile.h"
#include "map.h"

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


  string current_material;

  //quantity_of_material is a string because function getline takes a -
  //-string& str as second argument.
  string quantity_of_material;

  while ((file.peek() != EOF)) {

    getline(file, current_material, ' ');
    getline(file, quantity_of_material);

    city->add_material(current_material, stoi(quantity_of_material));

  }


  file.close();
  return true;

}

bool load_buildings(City* city) {

  ifstream file;
  file.open(BUILDING_FILE_ROUTE);

  if (!file) {

    // (Se que el enunciado me asegura que el archivo no va a estar vacio,
    //   pero nunca esta de mas checkear)
    cout << BOLD_RED << "ERROR!: " << DEFAULT_COLOR << "Could not find file: "
                                      "'edificios.txt', ending program" << endl;

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
    getline(file, max_building_quantity);

    //Creates the bulding struct in the record of the City
    city->add_building(building_type, stoi(stone_cost), stoi(wood_cost),
                        stoi(steel_cost), stoi(max_building_quantity));

    //Creates the Building object
    city->add_building(building_type, stoi(building_quantity), true);


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

int main(){

  system (CLR_SCREEN);

  Map map(3, 4);
  // map.add_tile("L"); // 0 0
  // map.add_tile("L"); // 0 1
  // map.add_tile("T");
  // map.add_tile("C");

  // map.consult(0, 2); // construible
  // map.consult(0, 1); // inaccesible
  // map.consult(0, 3); // transitable
  // map.consult(0, 0); // inaccesible

  City andypolis;

  bool not_end_program = true;

  not_end_program = load_buildings(&andypolis);

  if(not_end_program)
    not_end_program = load_materials(&andypolis);

  string user_option;


  while (not_end_program) {

    show_menu();

    std::cout << '\n' << "Please enter the option you want: ";
    std::cin >> user_option;

    if (user_option == "1" or user_option == "materials") {

      system (CLR_SCREEN);
      andypolis.show_materials();
      press_enter_to_continue();
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
      not_end_program = false;

    }

    else {

      system (CLR_SCREEN);
      std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR
            << "Invalid option, please enter a valid input" << '\n';
    }

  }

  return 0;

}
