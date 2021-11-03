#ifndef RECORD_HANDLER_H
#define RECORD_HANDLER_H
#include "list.h"

using namespace std;

struct Building_record{
  string building_type;
  int stone_cost = 0;
  int wood_cost = 0;
  int steel_cost = 0;
  int built_amount = 0;
  int max_quantity = 0;
};

class Record{

private:
  List<Building_record>* record;

public:
  Record();

  ~Record();

  void add_building(string building_type, int stone_cost, int wood_cost,
                        int steel_cost, int max_building_quantity);

  void modify_building_amount(string building_type, int modifier);

  int get_building_amount(string building_type);

  void show_record(int user_stone, int user_wood, int user_steel);

  string building_data_to_string();

  string get_current_building_type();

  int get_stone_cost(string building_type);

  int get_wood_cost(string building_type);

  int get_steel_cost(string building_type);

  void reset_current_node();

  void next_node();

  //PRE: -
  //POS:
  bool validate_building_type(string building_type);

  //PRE: -
  //POS:
  bool validate_building_amount(string building_type, int amount_of_buildings_built);

  //PRE: -
  //POS:
  bool validate_material_requirement(string building_type, int stone_amount,
                                      int wood_amount, int steel_amount);


};

#endif
