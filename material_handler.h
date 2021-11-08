#ifndef MATERIAL_HANDLER_H
#define MATERIAL_HANDLER_H
#include "list.h"
#include "material.h"

using namespace std;

class MaterialHandler{

private:
  List<Material>* materials;

public:
  MaterialHandler();

  ~MaterialHandler();

  void add_material(string material, int quantity);

  void show_materials();

  void set_material_amount(string material_to_modify, int new_quantity);

  int get_material_amount(string target_material);

  string generate_random_material_type();

  Material* generate_material(string material_type);

  string materials_data_to_string();


};

#endif
