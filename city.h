#ifndef CITY_H
#define CITY_H
#include "map.h"
#include "record.h"
#include "building_handler.h"
#include "material_handler.h"
using namespace std;


class City {
private:

  BuildingHandler* buildings;
  MaterialHandler* materials;
  Record* record;

  Map* city_map;

public:
  // PRE: -
  // POS: Creates a City object, with it's liked list pointers pointing to null-
  //       and a dinamic array of capacity = 5.
  City();

  // PRE: -
  // POS: Destroys City object and frees memory from linked lists-
  //        and dinamic array.
  ~City();


//--------------------------Material Management---------------------------------

  //PRE:
  //POS:
  void add_material(string new_material, int quantity); // Yes

  //PRE: -
  //POS: Prints in console all the material names are their respective quantity.
  void show_materials(); // Yes

  //PRE: -
  //POS: returns every material and it's quantity.
  string materials_data_to_string();

//-----------------------------Building Management------------------------------

  //PRE: the amount of built buildings from file edificios.txt must be a-
  //      interger > 0 to assure the correct functioning of- the rest of the program.

  //POS: Creates 'amount' of a Building object with it's building type =
  //      "building_type" and a node with it's pointer pointing to said Building.
  void add_building(string building_type, int x_coordinate, int y_coordinate, bool loading_from_txt);

  //PRE: -
  //POS: Destroys node and object Building who's building type = "building_type"-
  //     and user gets half of the construction materials rounded down.
  void demolish_building(int x_coordinate, int y_coordinate);

  //PRE: -
  //POS: Prints in console all the Buildings contained in the linked list.
  void show_buildings();


//-----------------------------Record Management--------------------------------

  // PRE: -
  // POS:
  void add_building(string building_type, int stone_cost, int wood_cost,
                    int steel_cost, int max_building_quantity);

  // PRE: -
  // POS:
  void show_record();

  //PRE: -
  //POS: returns all the building related information.
  string building_data_to_string();


//-------------------------------Map Management---------------------------------

//PRE: -
//POS: .
void generate_map(int rows, int columns);

//PRE: -
//POS: .
void add_tile(char tile_type);

//PRE: -
//POS: 0 <= x_coordinate < rows and 0 <= y_coordinate < columns
void consult_tile(int x_coordinate, int y_coordinate);


//--------------------------Names Management------------------------------------
bool validate_building_type(string type_to_check);


private:

//--------------------------Material Management---------------------------------

  //PRE: -
  //POS: Changes the quantity of the struct with "material_name" = "material_to_modify"
  //      to "new_quantity".
  void set_material_amount(string material_to_modify, int new_quantity);

  // //PRE: -
  // //POS: Returns the quantity of the material "material_name_to_obtain".
  int get_material_amount(string material_name_to_obtain);

};

#endif
