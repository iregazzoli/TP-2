#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include <fstream>
#include "constants.h"
using namespace std;

class Building{
private:
  string building_type;
  string material_that_produces;
  int x_coordinate;
  int y_coordinate;

public:
  //PRE: -
  //POS: Creates Building object initializing its attributes with the values ​​received by parameter.
  Building(string building_type, string material_that_produces, int x_coordinate, int y_coordinate);

  //PRE:-
  //POS:-
  virtual ~Building() {};

  //PRE: 'new_type' is a valid building.
  //POS: Changes building_type to 'new_type'.
  void set_type(string new_type);

  //PRE:-
  //POS: Returns building_type.
  string get_type();

  //PRE: 'new_x_coordinate' is a valide coordinate in map
  //POS: Changes x_coordinate to 'new_x_coordinate'.
  void set_x_coordinate(int new_x_coordinate);

  //PRE:-
  //POS: Returns 'x_coordinate'.
  int get_x_coordinate();

  //PRE: 'new_y_coordinate' is a valide coordinate in map
  //POS: Changes y_coordinate to 'new_y_coordinate'.
  void set_y_coordinate(int new_y_coordinate);

  //PRE:-
  //POS: Returns 'y_coordinate'.
  int get_y_coordinate();

  //PRE:-
  //POS: Returns the amount of material a building provides.
  virtual int produce_material();

  //PRE:-
  //POS: Returns 'material_that_produces'.
  string get_material_that_building_produces();

};

#endif //BUILDING_H
