#ifndef MATERIALS_H
#define MATERIALS_H
#include <iostream>
#include <fstream>
using namespace std;

class Material{
private:
    string material;
    int quantity;

public:

  Material(string material, int quantity);

  //PRE:-
  //POS:Returns material_type.
  string get_material();

  //PRE:-
  //POS: 
  void set_quantity(int new_quantity);

  //PRE:-
  //POS:.
  int get_quantity();
};

#endif