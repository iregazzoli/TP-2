#ifndef BUILDING_HANDLER_H
#define BUILDING_HANDLER_H
#include "list.h"
#include "building.h"

using namespace std;

class BuildingHandler{

private:
  List<Building>* buildings;

public:
  BuildingHandler();

  ~BuildingHandler();

  void add_building(string building_type, int x_coordinate, int y_coordinate);

  bool demolish_building(int x_coordinate, int y_coordinate);

  void show_building(string building_type, int amount_built);

  int get_building_built_amount(string building_type_to_count);

};

#endif
