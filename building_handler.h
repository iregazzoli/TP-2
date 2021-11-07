#ifndef BUILDING_HANDLER_H
#define BUILDING_HANDLER_H
#include "list.h"
#include "building.h"
#include "factory.h"
#include "mine.h"
#include "obelisk.h"
#include "power_plant.h"
#include "sawmill.h"
#include "school.h"

using namespace std;

class BuildingHandler{

private:
  List<Building>* buildings;

public:
  BuildingHandler();

  ~BuildingHandler();

  void add_building(string building_type, string material_that_produce, int x_coordinate, int y_coordinate);

  bool demolish_building(int x_coordinate, int y_coordinate);

  void show_buildings(string building_type, int amount_built);

  int get_building_built_amount(string building_type_to_count);

  Building* get_building(string building_type, int x_coordinate, int y_coordinate);

  int get_resources_amount(string building_type);

  string get_resources_type(string building_type);

  //PRE:-
  //POS: Returns all the building related information.
  string building_data_to_string();

};

#endif
