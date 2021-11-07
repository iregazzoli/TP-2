#include "menu.h"

using namespace  std;

void Menu::show_menu() {

  system (CLR_SCREEN);

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
  std::cout << BOLD_YELLOW << "[8]" << DEFAULT_COLOR << " Consult coordinate. ('8' or 'coordinate')" << '\n';
  std::cout << BOLD_YELLOW << "[9]" << DEFAULT_COLOR << " Show map ('9')" << '\n';

  return;

}

void Menu::save_data(City* city) {

  fstream material_file;
  material_file.open(MATERIAL_FILE_ROUTE, ios::out);

  if (material_file.is_open()) {

    material_file << city->materials_data_to_string();

    material_file.close();

  }

  fstream building_file;
  building_file.open(MAP_LOCATIONS_ROUTE, ios::out);

  if (building_file.is_open()) {

    building_file << city->building_data_to_string();

    building_file.close();

  }

}

void Menu::press_enter_to_continue() {

  std::cout << '\n';
  std::cin.ignore();
  std::cout << "Press ENTER to go back to the menu: ";
  std::cin.get();

}

bool Menu::interpretate_user_input(City* city, string user_option) {

  std::cout << '\n' << "Please enter the option you want: ";
  std::cin >> user_option;

  if (user_option == "1" or user_option == "materials") {

    system (CLR_SCREEN);

    city->show_materials();

    press_enter_to_continue();

    return true;

  }

  else if (user_option == "2" or user_option == "build") {

    build(city);

    press_enter_to_continue();

    return true;

  }

  else if (user_option == "3" or user_option == "buildings") {

    city->show_buildings();

    press_enter_to_continue();

    return true;

  }

  else if (user_option == "4" or user_option == "record") {

    city->show_record();

    press_enter_to_continue();

    return true;

  }

  else if (user_option == "5" or user_option == "demolish") {

    demolish(city);

    press_enter_to_continue();

    return true;

  }

  else if (user_option == "6" or user_option == "how_do_you_turn_this_on") {

    how_do_you_turn_this_on();

    press_enter_to_continue();

    return true;

  }

  else if (user_option == "7" or user_option == "exit"){

    save_data(city);
    std::cout << "Hope you enjoyed the program!" << '\n';
    return false;

  }

  else if (user_option == "8") {

    system (CLR_SCREEN);

    int x_coordinate = ask_user_x_coordinate(city);
    int y_coordinate = ask_user_y_coordinate(city);

    city->consult_tile(x_coordinate, y_coordinate);

    press_enter_to_continue();

    return true;

  }

  else if (user_option == "9") {

    system (CLR_SCREEN);

     city->show_map();

     press_enter_to_continue();

     return true;

   }


  else {

    system (CLR_SCREEN);

    std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR
          << "Invalid option, please enter a valid input" << '\n';

    return true;

  }

}

void Menu::how_do_you_turn_this_on() {

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

void Menu::build(City* city) {

  system (CLR_SCREEN);

  string building_to_add;

  std::cout << "Enter the type of building you wish to build (type exit to go back to menu): ";
  std::cin >> building_to_add;

  if(building_to_add == "planta"){

    string auxiliar;
    std::cin >> auxiliar;

  }

  while (!city->validate_building_type(lowercase_word(building_to_add)) && building_to_add != "exit") {

    std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR << "Please Enter a valid type: ";
    std::cin >> building_to_add; //we could instead do that if the user enters an invalid name it goes back to menu instaead of continuing the function

  }

  if (building_to_add != "exit") {

    std::cout << '\n';

    int x_coordinate = ask_user_x_coordinate(city);
    int y_coordinate = ask_user_y_coordinate(city);

    city->add_building(building_to_add, x_coordinate, y_coordinate, false);

  }

}

void Menu::demolish(City* city) {

  system (CLR_SCREEN);

  int x_coordinate = ask_user_x_coordinate(city);
  int y_coordinate = ask_user_y_coordinate(city);

  city->demolish_building(x_coordinate, y_coordinate);

}

int Menu::ask_user_x_coordinate(City* city) {

  int max_rows = city->get_max_rows();

  string x_coordinate;

  std::cout << "Enter the " << BOLD_YELLOW << "X" << DEFAULT_COLOR << " coordinate of building you wish to build: ";
  std::cin >> x_coordinate;

  while(!is_numeric(x_coordinate) || stoi(x_coordinate) < 0 || stoi(x_coordinate) > max_rows - 1) {

  std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR << BOLD_YELLOW << "X" << DEFAULT_COLOR <<
              " coordinate must be a number between" << BOLD_YELLOW << " 0 and " << max_rows - 1 << DEFAULT_COLOR << ": ";
  std::cin >> x_coordinate;

  }

  std::cout << '\n';

  return stoi(x_coordinate);

}

int Menu::ask_user_y_coordinate(City* city) {

  int max_columns = city->get_max_columns();

  string y_coordinate;

  std::cout << "Enter the " << BOLD_YELLOW << "Y" << DEFAULT_COLOR << " coordinate of building you wish to build: ";
  std::cin >> y_coordinate;

  while(!is_numeric(y_coordinate) || stoi(y_coordinate) < 0 || stoi(y_coordinate) > max_columns - 1) {

  std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR << BOLD_YELLOW << "Y" << DEFAULT_COLOR <<
              " coordinate must be a number between" << BOLD_YELLOW << " 0 and " << max_columns - 1 << DEFAULT_COLOR << ": ";
  std::cin >> y_coordinate;

  }

  std::cout << '\n';

  return stoi(y_coordinate);

}
