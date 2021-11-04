#include "material.h"


  Material::Material(string material, int quantity){
      this->material = material;
      this->quantity = quantity;
  }


  //PRE:-
  //POS:Returns material_type.
  string Material::get_material(){
      return material;
  }

  //PRE:-
  //POS: 
  void Material::set_quantity(int new_quantity){
      quantity = new_quantity;
  }

  //PRE:-
  //POS:.
  int Material::get_quantity(){
      return quantity;
  }

