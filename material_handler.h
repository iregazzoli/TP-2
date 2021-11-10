#ifndef MATERIAL_HANDLER_H
#define MATERIAL_HANDLER_H
#include "list.h"
#include "material.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

class MaterialHandler{

private:
  List<Material>* materials;

public:
  
  //PRE:-
  //POS: Creates a MaterialHandler object, with it's liked list pointers pointing to null.
  MaterialHandler();

  //PRE:-
  //POS: Destroys MaterialHandler object and frees memory from linked list.
  ~MaterialHandler();

  //PRE: 'material' must be a material valid and quantity >= 0.
  //POS: Creates a new object according to material.
  void add_material(string material, int quantity);

  //PRE: 'material' must be a material valid and quantity >= 0.
  //POS: Shows on screen type of material and available quantity of it.
  void show_materials();

  //PRE: 'material' must be a material valid and quantity >= 0.
  //POS: Modify the amount of material.
  void set_material_amount(string material_to_modify, int new_quantity);

  //PRE: 'target_material' must be a material valid.
  //POS: Returns the amount of 'target_material'.
  int get_material_amount(string target_material);

  //PRE:-
  //POS: Returns a random material between STONE, WOOD and STEEL.
  string generate_random_material_type();

  //PRE: 'material_type' must be a material valid.
  //POS: Creates a new material object and returns its pointer.
  Material* generate_material(string material_type);

  //PRE:-
  //POS: Returns all materials and available quantity of each.
  string materials_data_to_string();

};

#endif //MATERIAL_HANDLER_H
