#ifndef CITY_H
#define CITY_H
#include "node.h"
#include "map.h"
#include <iomanip>
#include "system.h"
#include "constants.h"
using namespace std;

struct Building_record{
  string building_type;
  int stone_cost = 0;
  int wood_cost = 0;
  int steel_cost = 0;
  int max_quantity = 0;
};

struct Material{
  string material_name;
  int quantity = 0;
};

class City {
private:

  Node<Building>* first_building_node;
  Node<Material>* first_material_node;

  int record_capacity;
  int current_position;
  Building_record* record;

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

  //PRE: Quantity must be a interger > 0 to assure the correct functioning of-
  //      the rest of the program.

  //POS: Creates a struct with "new_material" and "quantity" as parameters-
  //       and a node with it's pointer pointing to said struct.
  void add_material(string new_material, int quantity);

  //PRE: -
  //POS: Prints in console all the material names are their respective quantity.
  void show_materials();

  //PRE: -
  //POS: returns every material and it's quantity.
  string materials_data_to_string();

//-----------------------------Building Management------------------------------

  //PRE: the amount of built buildings from file edificios.txt must be a-
  //      interger > 0 to assure the correct functioning of- the rest of the program.

  //POS: Creates 'amount' of a Building object with it's building type =
  //      "building_type" and a node with it's pointer pointing to said Building.
  void add_building(string building_type, int amount, bool loading_from_txt);

  //PRE: -
  //POS: Destroys node and object Building who's building type = "building_type"-
  //     and user gets half of the construction materials rounded down.
  void demolish_building(string building_type);

  //PRE: -
  //POS: Prints in console all the Buildings contained in the linked list.
  void show_buildings();


//-----------------------------Record Management--------------------------------

  // PRE: -
  // POS: Adds a Building Struct to the dinamic array with the parameters pass-
  //       to the method, in case of the array being full creates a new dinamic-
  //        array with +5 capacity and copies all the structs to the new one.
  void add_building(string building_type, int stone_cost, int wood_cost,
                    int steel_cost, int max_building_quantity);

  // PRE: -
  // POS: Prints in console all the parameters from each Struct inside the-
  //       dinamic array.
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


private:

//--------------------------Material Management---------------------------------

  //PRE: -
  //POS: Changes the quantity of the struct with "material_name" = "material_to_modify"
  //      to "new_quantity".
  void set_material_amount(string material_to_modify, int new_quantity);

  // //PRE: -
  // //POS: Returns the quantity of the material "material_name_to_obtain".
  int get_material_amount(string material_name_to_obtain);

  // PRE:-
  // POS: Function to aid the destructor to free memory, destroys every struct-
  //       inside every node and the nodes itself.
  void clear_material_list();

//-----------------------------Building Management------------------------------

  //PRE: -
  //POS: returns quantity of Buildings built of type = "building_type".
  int get_building_quantity(string building_type);

  // PRE:-
  // POS: Function to aid the destructor to free memory, frees every node and-
  //       Building object from the Building linked list.
  void clear_building_list();

  //PRE: -
  //POS: Checks if the building type is equal to one on the edificios.txt
  bool validate_building_type(string building_type);

  //PRE: -
  //POS: Checks if the amount of buildings to build doesn't surpass the
  //      max quantity of said building.
  bool validate_building_amount(string building_type, int amount_to_build);

  //PRE: -
  //POS: Checks if the amount of materials required to build the building is enough
  bool validate_material_requirement(string building_type);


//-----------------------------Record Management--------------------------------
  //PRE: -
  //POS: returns current_position == record_capacity.
  bool full_record();

//------------------------------Names Management--------------------------------
  //PRE: -
  //POS: returns the word in lowercase.
  string lowercase_word(string word);

  //PRE: -
  //POS: returns the word capitalized.
  string capitalize_word(string word);

};

#endif
