#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include <fstream>
using namespace std;

class Building{
private:
  string building_type;

public:
  //PRE: -
  //POS: Creates Building object with building_type = 'type'.
  Building(string type);

  //PRE:-
  //POS: Changes building_type to 'new_type'.
  void set_type(string new_type);

  //PRE:-
  //POS:Returns building_type.
  string get_type();
};

#endif
