#include "material_handler.h"

MaterialHandler::MaterialHandler(){

  materials = new List<Material>;

}

void MaterialHandler::add_material(string material, int quantity){

  Material* new_material = new Material{material, quantity};
  materials->add_node(new_material);

}

void MaterialHandler::show_materials(){

  materials->reset_current_node();

  while(materials->get_current_value() != 0){

    string capitalized_material = capitalize_word(materials->get_current_value()->material_name);

    if (materials->get_current_value()->material_name == "piedra") {

      std::cout << left << setw(WIDTH) << "Material: " << BOLD_BLACK <<
       setw(WIDTH) << capitalized_material << DEFAULT_COLOR
        << setw(WIDTH) << " Quantity: "<< BOLD_BLUE << setw(WIDTH) <<
          materials->get_current_value()->quantity << DEFAULT_COLOR << '\n';
    }

    else if (materials->get_current_value()->material_name == "madera") {

      std::cout << left << setw(WIDTH) << "Material: " << BOLD_GREEN <<
       setw(WIDTH) << capitalized_material << DEFAULT_COLOR
        << setw(WIDTH) << " Quantity: "<< BOLD_BLUE << setw(WIDTH) <<
          materials->get_current_value()->quantity << DEFAULT_COLOR << '\n';

    }

    else if (materials->get_current_value()->material_name == "metal") {

      std::cout << left << setw(WIDTH) << "Material: " << BOLD_CYAN <<
       setw(WIDTH) << capitalized_material << DEFAULT_COLOR
        << setw(WIDTH) << " Quantity: "<< BOLD_BLUE << setw(WIDTH) <<
          materials->get_current_value()->quantity << DEFAULT_COLOR << '\n';

    }

    else {

      std::cout << left << setw(WIDTH) << "Material: " << BOLD_YELLOW <<
       setw(WIDTH) << capitalized_material << DEFAULT_COLOR
        << setw(WIDTH) << " Quantity: "<< BOLD_BLUE << setw(WIDTH) <<
          materials->get_current_value()->quantity << DEFAULT_COLOR << '\n';


    }

    materials->next_node();

  }

}

void MaterialHandler::set_material_amount(string material_to_modify, int new_quantity) {

  std::cout << "MAterial: " << material_to_modify << " new quantity: " <<  new_quantity << '\n' << '\n';

  materials->reset_current_node();

  while (materials->get_current_value() != 0) {

    if (materials->get_current_value()->material_name == material_to_modify)
      materials->get_current_value()->quantity = new_quantity;

    std::cout << "MAterial: " << materials->get_current_value()->material_name << " new quantity: " <<  materials->get_current_value()->quantity << '\n';
    materials->next_node();

  }
}

int MaterialHandler::get_material_amount(string target_material){

  materials->reset_current_node();

  while (materials->get_current_value() != 0) {

    if (materials->get_current_value()->material_name == target_material)
      return materials->get_current_value()->quantity;

    materials->next_node();

  }

  return -1;
}

string MaterialHandler::materials_data_to_string() {

  string new_materials;

  materials->reset_current_node();

  while (materials->get_current_value() != 0) {

    new_materials = new_materials + materials->get_current_value()->material_name + " ";
    new_materials = new_materials + to_string(materials->get_current_value()->quantity) + "\n";

    materials->next_node();
  }

  return new_materials;

}

MaterialHandler::~MaterialHandler(){

  materials->reset_current_node();

  delete materials;

}