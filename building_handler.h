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

  //PRE:-
  //POS: Creates a BuildingHandler object, with it's liked list pointers pointing to null.
  BuildingHandler();

  //PRE:-
  //POS: Destroys BuildingHandler object and frees memory from linked list.
  ~BuildingHandler();

  //PRE: 'building_type' must be MINE, SAWMILL, FACTORY, SCHOOL, OBELISK or POWER_PLANT.
  //     'material_that_produce' must be STONE, WOOD or STEEL. 'x_coordinate' and 'y_coordinate' must be valid map coordinates.
  //POS: Creates a new object according to building_type.
  void add_building(string building_type, string material_that_produce, int x_coordinate, int y_coordinate);

  //PRE: 'x_coordinate' and 'y_coordinate' must be valid map coordinates.
  //POS: Returns true if the building can be demolished at those coordinates, false otherwise.
  bool demolish_building(int x_coordinate, int y_coordinate);

  //PRE: 'building_type' must be a valid building and 'amount_built' >= 0.
  //POS: Shows on screen amount of buildings built.
  void show_buildings(string building_type, int amount_built);

  //PRE: 'building_type_to_count' must be a valid building.
  //POS: Returns the amount of 'building_type_to_count'.
  int get_building_built_amount(string building_type_to_count);

  //PRE: 'building_type' must be a valid building. 'x_coordinate' and 'y_coordinate' must be valid map coordinates.
  //POS: Returns the Building pointer pointing to 'building_type'.
  Building* get_building(string building_type, int x_coordinate, int y_coordinate);

  //PRE: 'building_type' must be a valid building.
  //POS: Returns amount of material that 'building_type' produces.
  int get_resources_amount(string building_type);

  //PRE: 'building_type' must be a valid building.
  //POS: Returns  material type that 'building_type' produces.
  string get_resources_type(string building_type);

  //PRE:-
  //POS: Returns all the buildings built, the amount there are and their respective coordinates.
  string building_data_to_string();

};

#endif //BUILDING_HANDLER_H
