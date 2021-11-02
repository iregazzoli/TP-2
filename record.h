#ifndef RECORD_HANDLER_H
#define RECORD_HANDLER_H
#include "list.h"

using namespace std;

struct Building_record{
  string building_type;
  int stone_cost = 0;
  int wood_cost = 0;
  int steel_cost = 0;
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

  void show_record();

  string building_data_to_string();

  string get_current_building_type();


};

#endif
