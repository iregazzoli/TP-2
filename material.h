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

  //PRE:-
  //POS: Created Material object whit 'material' = material and 'quantity' = quantity.
  Material(string material, int quantity);

  //PRE:-
  //POS:Returns material_type.
  string get_material();

  //PRE: new_quantity >= 0.
  //POS: Changes building_type to 'new_type'.
  void set_quantity(int new_quantity);

  //PRE:-
  //POS: Returns quantity.
  int get_quantity();
};

#endif //MATERIALS_H
