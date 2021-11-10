#ifndef CITY_H
#define CITY_H
#include "map.h"
#include "record.h"
#include "building_handler.h"
#include "material_handler.h"
#include "empty_passable_tiles.h"
using namespace std;


class City {
private:

  BuildingHandler* buildings;
  MaterialHandler* materials;
  Record* record;
  Map* city_map;
  EmptyPassableTiles* passable_tiles;

public:

  // PRE: -
  // POS: Creates a City object. Creates a new BuildingHandler, new MaterialHandler, new Record, new EmptyPassableTiles
  //      and 'city_map' is zero-initialized.
  City();

  // PRE: -
  // POS: Destroys City object and frees memory from linked lists-
  //        and dinamic matrix.
  ~City();


//--------------------------Material Management---------------------------------

  //PRE: 'new_material' must be a valid material of materiales.txt. 'quantity' >= 0.
  //POS: Creates a new Material object 'new_material' and a node whit it's pointer to said Material. 
  void add_material(string new_material, int quantity);

  //PRE: -
  //POS: Prints in console all the material names are their respective quantity.
  void show_materials();

  //PRE: -
  //POS: Collects materials produced by the constructed buildings, increasing the amounts of them.
  void collect_resources();

  //PRE: -
  //POS: Randomly generates a material type and a random amount of it.
  void material_rain();

  //PRE: -
  //POS: Returns every material and it's quantity.
  string materials_data_to_string();


//-----------------------------Building Management------------------------------

  //PRE: the amount of built buildings from file edificios.txt must be a-
  //      interger > 0 to assure the correct functioning of- the rest of the program.
  //POS: Creates 'amount' of a Building object with it's building type =
  //      "building_type" and a node with it's pointer pointing to said Building.
  void add_building(string building_type, int x_coordinate, int y_coordinate, bool loading_from_txt);

  //PRE: -
  //POS: Destroy the node and the Building object at those coordinates and the user gets 
  //     half of the building materials rounded down.
  void demolish_building(int x_coordinate, int y_coordinate);

  //PRE: -
  //POS: Prints in console all the Buildings contained in the linked list.
  void show_buildings();

  //PRE: -
  //POS: Return true if 'type_to_check' is a building from the buildings.txt file.
  bool validate_building_type(string type_to_check);

//-----------------------------Record Management--------------------------------

  // PRE: The amount of built buildings from file edificios.txt must be a-
  //      interger > 0 to assure the correct functioning of- the rest of the program and stone_cost,
  //      wood_cost, steel_cost, max_building_quantity all must be > 0.
  // POS: Load the record list with the buildings read in edificios.txt.
  void add_building(string building_type, int stone_cost, int wood_cost,
                    int steel_cost, int max_building_quantity);

  // PRE: -
  // POS: Shows on screen all building information and all the material names are their respective quantity.
  void show_record();

  //PRE: -
  //POS: returns all the building related information.
  string building_data_to_string();


//-------------------------------Map Management---------------------------------

  //PRE: 'row' >= 0 and 'columns' >= 0. 
  //POS: Create a new map object.
  void generate_map(int rows, int columns);

  //PRE: 'tile_type' must be a LAKE, TERRAIN or ROAD. 'x_coordinate' and 'y_coordinate' 
  //     must be valid map coordinates.
  //POS: Loads 'city_map' with tiles and if tile is ROAD it also loads it in 'passable_tiles'.
  void add_tile(char tile_type, int x_coordinate, int y_coordinate);

  //PRE: 'x_coordinate' and 'y_coordinate' must be valid map coordinates.
  //POS: Shows on screen the tile type and if its empty or the content.
  void consult_tile(int x_coordinate, int y_coordinate);

  //PRE: -
  //POS: Returns the map rows.
  int get_max_rows();

  //PRE: -
  //POS: Returns the map columns.
  int get_max_columns();

  //PRE: -
  //POS: Shows on screen the map with icons representing buildings, materials and tiles types. 
  void show_map();


private:

//----------------------------Material Management-------------------------------

  //PRE: -
  //POS: Changes the quantity of the object with "material_name" = "material_to_modify"
  //      to "new_quantity".
  void set_material_amount(string material_to_modify, int new_quantity);

  // //PRE: -
  // //POS: Returns the quantity of the material "material_name_to_obtain".
  int get_material_amount(string material_name_to_obtain);

  //PRE: 'building_type' must be a valid building.'user_stone', 'user_wood' and 'user_steel' all 
  //      must be greater than or equal to the cost of construction of the building.
  //POS: Discounts cost of the building from total materials.
  void deduct_building_cost(int user_stone, int user_wood, int user_steel, string building_type);

  //PRE: 'building_type' must be a valid building. 
  //POS: Refunds building cost.
  void refund_building_cost(string building_type);


//----------------------------Building Management-------------------------------

  //PRE: 'building_type' must be MINE, SAWMILL, FACTORY, SCHOOL, OBELISK or POWER_PLANT.
  //POS: Adds a new building to the map at these coordinates and also add it to the list of buildings. 
  //     Increase amount of buildings built.
  void add_building(string building_type, string material_that_produces, int x_coordinate, int y_coordinate);

  //PRE: -
  //POS: Prints a message on the screen according to the error found.
  void print_error_message(bool valid_type, bool valid_amount, bool enough_materials,
                            bool valid_tile, bool empty_tile, bool loading_from_txt,
                            string building_type, int x_coordinate, int y_coordinate);

  //PRE: -
  //POS: Returns what type of material it produces 'building_type'.
  string get_resource_that_building_produces(string building_type);

};

#endif//CITY_H
