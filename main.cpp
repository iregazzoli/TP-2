#include "menu.h"
#include "inaccesible_tile.h"
#include "buildable_tile.h"
#include "passable_tile.h"

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

bool load_buildings_attributes(City* city) {

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
  string max_building_quantity;

  while ((file.peek() != EOF)) {

    getline(file, building_type, ' ');
    getline(file, stone_cost, ' ');
    getline(file, wood_cost, ' ');
    getline(file, steel_cost, ' ');
    getline(file, max_building_quantity);

    //Creates the bulding struct in the record of the City
    city->add_building(building_type, stoi(stone_cost), stoi(wood_cost),
                        stoi(steel_cost), stoi(max_building_quantity));

  }

  file.close();
  return true;

}

bool load_buildings(City* city){

  ifstream file;

  file.open(MAP_LOCATIONS_ROUTE);

  if (!file) {

    cout << BOLD_RED << "ERROR!:" <<  DEFAULT_COLOR << " Could not find file: "
                                     "'ubicaciones.txt', ending program" << endl;
    return false;

  }

  //both are string because function getline takes a - string& str as second argument.

  string building_type;
  string x_coordinate;
  string y_coordinate;
  string aux;

  while ((file.peek() != EOF)) {

    getline(file, building_type, ' ');
    getline(file, aux, '(');
    getline(file, x_coordinate, ',');
    getline(file, aux, ' ');
    getline(file, y_coordinate, ')');
    getline(file, aux);

    city->add_building(building_type, stoi(x_coordinate), stoi(y_coordinate), true);

  }

  file.close();
  return true;

}

bool load_tiles(City* city){

  ifstream file;
  file.open(MAP_FILE_ROUTE);

  if (!file) {

    cout << BOLD_RED << "ERROR!:" <<  DEFAULT_COLOR << " Could not find file: "
                                     "'mapa.txt', ending program" << endl;
    return false;

  }

  //both are string because function getline takes a - string& str as second argument.

  string total_of_rows;
  string total_of_columns;

  getline(file, total_of_rows, ' ');
  getline(file, total_of_columns);

  city->generate_map(stoi(total_of_rows), stoi(total_of_columns));

  string line;
  char tile_type;

  while ((file.peek() != EOF)) {

    getline(file, line);

    stringstream ss(line); //from API stringstream

    while (ss >> tile_type) {

      city->add_tile(tile_type);

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

int main(){

  system (CLR_SCREEN);

  City andypolis;

  bool not_end_program = true;

  not_end_program = load_buildings_attributes(&andypolis);

  if(not_end_program)
    not_end_program = load_materials(&andypolis);

  // if(not_end_program)
  //   not_end_program = load_tiles(&andypolis);


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
