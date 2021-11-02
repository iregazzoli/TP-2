#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include <fstream>
using namespace std;

class Building{
private:
  string building_type;
  int x_coordinate;
  int y_coordinate;

public:
  //PRE: -
  //POS: Creates Building object with building_type = 'type'. [modify]
  Building(string building_type, int x_coordinate, int y_coordinate);

  //PRE:-
  //POS: Changes building_type to 'new_type'.
  void set_type(string new_type);

  //PRE:-
  //POS:Returns building_type.
  string get_type();

  //PRE:-
  //POS:
  void set_x_coordinate(int x_coordinate);

  //PRE:-
  //POS:
  int get_x_coordinate();

  //PRE:-
  //POS:
  void set_y_coordinate(int y_coordinate);

  //PRE:-
  //POS:
  int get_y_coordinate();


};

#endif
