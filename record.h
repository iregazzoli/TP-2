#ifndef RECORD_HANDLER_H
#define RECORD_HANDLER_H
#include "list.h"

using namespace std;

struct BuildingRecord{
  string building_type;
  int stone_cost = 0;
  int wood_cost = 0;
  int steel_cost = 0;
  int built_amount = 0;
  int max_quantity = 0;
};

class Record{

private:
  List<BuildingRecord>* record;

public:

  //PRE:-
  //POS: Create a record object.
  Record();

  //PRE:-
  //POS: Destroy record object.
  ~Record();


  //PRE: The amount of built buildings from file edificios.txt must be a-
  //     interger > 0 to assure the correct functioning of- the rest of the program and stone_cost,
  //     wood_cost, steel_cost, max_building_quantity all must be > 0.
  //POS: Create a new record object with the attributes received by parameter and add a new node to list.
  void add_building(string building_type, int stone_cost, int wood_cost,
                        int steel_cost, int max_building_quantity);

  //PRE: building_type must be a building valid building and modifier >= 0.
  //POS: Change building amount for the building amount + modifier.
  void modify_building_amount(string building_type, int modifier);

  //PRE: buildin_type must be a building valid building.
  //POS: get building amount.
  int get_building_amount(string building_type);

  //PRE: user_stone, user_wood and user_steel all must be > 0.
  //POS: Show the attributes of record object.
  void show_record(int user_stone, int user_wood, int user_steel);

  //PRE:-
  //POS: Returns building_type and if it is empty returns "0".
  string get_current_building_type();

  //PRE: buildin_type must be a building valid building.
  //POS: Returns stone_cost.
  int get_stone_cost(string building_type);

  //PRE: buildin_type must be a building valid building.
  //POS: Returns wood_cost.
  int get_wood_cost(string building_type);

  //PRE: buildin_type must be a building valid building.
  //POS: Returns steel_cost.
  int get_steel_cost(string building_type);

  //PRE: -
  //POS: If buildin_type is in "edificio.txt" returns true, false otherwise.
  bool validate_building_type(string building_type);

  //PRE: buildin_type must be a building valid building.
  //POS: If amount_of_buildings_built + 1 <= max_quantity return true, false otherwise.
  bool validate_building_amount(string building_type, int amount_of_buildings_built);

  //PRE: buildin_type must be a building valid building.
  //POS: If you have the amount of material needed to build it returns true, false otherwise.
  bool validate_material_requirement(string building_type, int stone_amount,
                                      int wood_amount, int steel_amount);


  //PRE:-
  //POS: Reset current node.
  void reset_current_node();

  //PRE: -
  //POS: Advance to the next node
  void next_node();

};

#endif
