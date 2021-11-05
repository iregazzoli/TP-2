#include "city.h"


City::City(){

  buildings = new BuildingHandler;
  materials = new MaterialHandler;
  record = new Record;
  city_map = 0;

}


//--------------------------Material Management---------------------------------

void City::add_material(string material, int quantity) {

  string lowercase_material = lowercase_word(material);

  materials->add_material(lowercase_material, quantity);

}

void City::show_materials() {

  materials->show_materials();

}

string City::materials_data_to_string() {

  return materials->materials_data_to_string();

}


//--------------------------Private Material Methods----------------------------

void City::set_material_amount(string material_to_modify, int new_quantity) {

  materials->set_material_amount(material_to_modify, new_quantity);

}

int City::get_material_amount(string target_material) {

  return materials->get_material_amount(target_material);

}

//-----------------------------Building Management------------------------------

void City::add_building(string building_type, int x_coordinate, int y_coordinate,
                         bool loading_from_txt){

  string lowercase_building_type = lowercase_word(building_type);
  string capitalize_building_type = capitalize_word(lowercase_building_type);


  bool valid_type = record->validate_building_type(lowercase_building_type);


  bool valid_tile = false;

  if (valid_type)
    valid_tile = city_map->tile_buildable(x_coordinate, y_coordinate);

  else
    valid_tile = true;


  bool empty_tile = false;

  if (valid_type && valid_tile)
    empty_tile = city_map->tile_empty(x_coordinate, y_coordinate);

  else
    empty_tile = true;


  bool valid_amount = false;

  if (valid_type && valid_tile && empty_tile && !loading_from_txt) {

    int amount_built = record->get_building_amount(lowercase_building_type);

    valid_amount = record->validate_building_amount(lowercase_building_type, amount_built);

  }

  else
    valid_amount = true;



  bool enough_materials = false;

  int user_stone = materials->get_material_amount("piedra");
  int user_wood = materials->get_material_amount("madera");
  int user_steel = materials->get_material_amount("metal");

  if (!loading_from_txt && valid_type && valid_amount && valid_tile) {

    enough_materials = record->validate_material_requirement(lowercase_building_type,
                                            user_stone, user_wood, user_steel);
  }

  else {

    enough_materials = true;

  }

  //Section related with building by user command
  if (valid_type && valid_tile && empty_tile && valid_amount && enough_materials && !loading_from_txt) {

    string user_confirmation;

    std::cout << "Are you sure you want to add a building: " << BOLD_GREEN
                << capitalize_building_type << DEFAULT_COLOR << " (y/n): ";

    std::cin >> user_confirmation;

    if (user_confirmation == "y" || user_confirmation == "yes") {

      int stone_cost = record->get_stone_cost(lowercase_building_type);
      int wood_cost = record->get_wood_cost(lowercase_building_type);
      int steel_cost = record->get_steel_cost(lowercase_building_type);

      materials->set_material_amount("piedra", user_stone - stone_cost);
      materials->set_material_amount("madera", user_wood - wood_cost);
      materials->set_material_amount("metal", user_steel - steel_cost);

      buildings->add_building(lowercase_building_type, x_coordinate, y_coordinate);
      record->modify_building_amount(lowercase_building_type, 1);
      Building* new_building = buildings->get_building(lowercase_building_type, x_coordinate, y_coordinate);
      city_map->add_building(new_building, x_coordinate, y_coordinate);

      std::cout << BOLD_GREEN<< "Building: " << capitalize_building_type
                  << ", successfully built." << DEFAULT_COLOR << '\n';

    }

    else {
      std::cout << BOLD_RED << "ERROR:" << DEFAULT_COLOR << " Building: "
                  << BOLD_GREEN << capitalize_building_type << DEFAULT_COLOR
                    << " wasn't successfully constucted."<< '\n';
    }

  }


  else if (!valid_type && valid_amount && enough_materials && valid_tile && empty_tile && !loading_from_txt) {
    std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR <<
                 "Invalid building type: " << capitalize_building_type <<
                  ", check menu option '4' to see all valid types." << '\n';
  }

  else if (valid_type && !valid_amount && enough_materials && valid_tile && empty_tile && !loading_from_txt) {
  std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR << "Building type: " <<
                capitalize_building_type << " surpasses max quantity allow,"
                " check menu option '3' to see amount built." << '\n';
  }

  else if (valid_type && valid_amount && !enough_materials && valid_tile && empty_tile && !loading_from_txt) {
    std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR <<
                  "You don't have enough materials to build building: " <<
                    capitalize_building_type << ", check menu option '1' and '4' to see "
                     "materials amount and building costs." << '\n';
  }

  else if (valid_type && valid_amount && enough_materials && !valid_tile && empty_tile && !loading_from_txt) {
    std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR <<
                  "The tile where you are trying to build on is not meant for building,"
                    " check menu option - to see the map with all the buildable tiles." << '\n';
  }

  else if (valid_type && valid_amount && enough_materials && valid_tile && !empty_tile && !loading_from_txt) {
    std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR <<
                  "The tile where you are trying to build already has a building in it,"
                    " check menu option - to see the map with all the built buildings." << '\n';
  }


  //Section related with building by txt file
  if(valid_type && valid_tile && empty_tile && loading_from_txt) {

    buildings->add_building(building_type, x_coordinate, y_coordinate);
    record->modify_building_amount(building_type, 1);
    Building* new_building = buildings->get_building(lowercase_building_type, x_coordinate, y_coordinate);
    city_map->add_building(new_building, x_coordinate, y_coordinate);

  }

  else if(valid_type && !valid_tile && empty_tile && loading_from_txt) {

    std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR << "Invalid tile for building: " <<
               BOLD_GREEN << capitalize_building_type << DEFAULT_COLOR << ", coordinates: (" <<
                BOLD_YELLOW << x_coordinate << ", " << y_coordinate << DEFAULT_COLOR <<
                 ") in file: " << BOLD_BLUE << MAP_LOCATIONS_ROUTE << DEFAULT_COLOR << '\n';

    std::cout << BOLD_RED << "Building: " << capitalize_building_type << " wasn't built" << DEFAULT_COLOR << '\n';

  }

  else if(valid_type && valid_tile && !empty_tile && loading_from_txt) {

    std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR << "Tile: (" <<
               BOLD_YELLOW << x_coordinate << ", " << y_coordinate << DEFAULT_COLOR <<
                ") in file: " << BOLD_BLUE << MAP_LOCATIONS_ROUTE << DEFAULT_COLOR <<
                 " already has a building in it" <<'\n';

    std::cout << BOLD_RED << "Building: " << capitalize_building_type << " wasn't built" << DEFAULT_COLOR << '\n';

  }

}


void City::demolish_building(int x_coordinate, int y_coordinate) {

  bool valid_tile = city_map->tile_buildable(x_coordinate, y_coordinate);

  bool empty_tile = true;

  if (valid_tile) {

    empty_tile = city_map->tile_empty(x_coordinate, y_coordinate);

  }

  string building_type;
  string capitalize_building_type;
  string lowercase_building_type;

  bool building_demolished = false;

  if(valid_tile && !empty_tile) {

    building_type = city_map->get_building_type(x_coordinate, y_coordinate);
    capitalize_building_type = capitalize_word(building_type);
    lowercase_building_type = lowercase_word(building_type);

    building_demolished = buildings->demolish_building(x_coordinate, y_coordinate);

    city_map->remove_building(x_coordinate, y_coordinate);

  }


  if (building_demolished) {

    record->modify_building_amount(building_type, -1);

    int user_stone = materials->get_material_amount("piedra");
    int user_wood = materials->get_material_amount("madera");
    int user_steel = materials->get_material_amount("metal");

    int stone_cost = record->get_stone_cost(lowercase_building_type);
    int wood_cost = record->get_wood_cost(lowercase_building_type);
    int steel_cost = record->get_steel_cost(lowercase_building_type);

    materials->set_material_amount("piedra", user_stone + stone_cost / 2);
    materials->set_material_amount("madera", user_wood + wood_cost / 2);
    materials->set_material_amount("metal", user_steel + steel_cost / 2);

  }

  if (building_demolished)
    std::cout << BOLD_GREEN << "Building: '" << capitalize_building_type <<
                            "' successfully demolish." << DEFAULT_COLOR << '\n';

  else if (valid_tile && empty_tile)
    std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR << "There isn't"
               " a building in tile with coordinates: (" << BOLD_YELLOW <<
                x_coordinate << ", " << y_coordinate << DEFAULT_COLOR << ")" << '\n';

  else if (!valid_tile && empty_tile)
    std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR << "The tile with coordinates: ("
               << BOLD_YELLOW << x_coordinate << ", " << y_coordinate << DEFAULT_COLOR <<
               ") is not suited for building." << '\n';


}


void City::show_buildings() {

  system (CLR_SCREEN);

  record->reset_current_node();

  while(record->get_current_building_type() != "0"){

    int amount_built = buildings->get_building_built_amount(record->get_current_building_type());

    if(amount_built > 0){

      buildings->show_building(record->get_current_building_type(), amount_built);

    }

    record->next_node();

  }

}


//-----------------------------Record Management--------------------------------

void City::add_building(string building_type, int stone_cost, int wood_cost,
                        int steel_cost, int max_building_quantity) {

    record->add_building(building_type, stone_cost, wood_cost, steel_cost, max_building_quantity);

}


void City::show_record() {

  system (CLR_SCREEN);

  int user_stone = materials->get_material_amount("piedra");
  int user_wood = materials->get_material_amount("madera");
  int user_steel = materials->get_material_amount("metal");

  record->show_record(user_stone, user_wood, user_steel);

  std::cout << "Remember your current materials are: " << '\n';
  materials->show_materials();

}


string City::building_data_to_string() {

  return record->building_data_to_string();

}

//-------------------------------Map Management---------------------------------

void City::generate_map(int rows, int columns) {

  city_map = new Map(rows, columns);

}

void City::add_tile(char tile_type){

  city_map->add_tile(tile_type);

}

void City::consult_tile(int x_coordinate, int y_coordinate) {

  city_map->consult(x_coordinate, y_coordinate);

}

int City::get_max_rows() {

  return city_map->get_rows();

}

int City::get_max_columns(){

  return city_map->get_columns();

}


//------------------------Private Map Management--------------------------------


//--------------------------Names Management------------------------------------
bool City::validate_building_type(string type_to_check){

  return record->validate_building_type(type_to_check);

}


//------------------------------------------------------------------------------

City::~City() {

  delete buildings;
  delete materials;
  delete record;
  delete city_map; // we still need to write this one.

}
