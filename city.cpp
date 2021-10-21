#include "city.h"


City::City(){
}


//--------------------------Material Management---------------------------------

void City::add_material(string material, int quantity) {

  string lowercase_material = lowercase_word(material);

  //create the struct new_material in the heap
  Material* new_material = new Material{lowercase_material, quantity};
  Node<Material>* new_node = new Node<Material>(new_material);

  new_node->set_next_node(first_material_node);

  first_material_node = new_node;

}


void City::show_materials() {

  Node<Material>* current_node = first_material_node;

  while (current_node != 0) {

    string capitalized_material = current_node->get_value()->material_name;
    capitalized_material[0] = toupper(capitalized_material[0]);

    if (current_node->get_value()->material_name == "piedra") {

      std::cout << left << setw(WIDTH) << "Material: " << BOLD_BLACK <<
       setw(WIDTH) << capitalized_material << DEFAULT_COLOR
        << setw(WIDTH) << " Quantity: "<< BOLD_BLUE << setw(WIDTH) <<
          current_node->get_value()->quantity << DEFAULT_COLOR << '\n';
    }

    else if (current_node->get_value()->material_name == "madera") {

      std::cout << left << setw(WIDTH) << "Material: " << BOLD_GREEN <<
       setw(WIDTH) << capitalized_material << DEFAULT_COLOR
        << setw(WIDTH) << " Quantity: "<< BOLD_BLUE << setw(WIDTH) <<
          current_node->get_value()->quantity << DEFAULT_COLOR << '\n';

    }

    else if (current_node->get_value()->material_name == "metal") {

      std::cout << left << setw(WIDTH) << "Material: " << BOLD_CYAN <<
       setw(WIDTH) << capitalized_material << DEFAULT_COLOR
        << setw(WIDTH) << " Quantity: "<< BOLD_BLUE << setw(WIDTH) <<
          current_node->get_value()->quantity << DEFAULT_COLOR << '\n';

    }

    else {

      std::cout << left << setw(WIDTH) << "Material: " << BOLD_YELLOW <<
       setw(WIDTH) << capitalized_material << DEFAULT_COLOR
        << setw(WIDTH) << " Quantity: "<< BOLD_BLUE << setw(WIDTH) <<
          current_node->get_value()->quantity << DEFAULT_COLOR << '\n';


    }

    current_node = current_node->get_next_node();

  }
}


//--------------------------Private Material Methods----------------------------

void City::set_material_amount(string material_to_modify, int new_quantity) {

  Node<Material>* current_node = first_material_node;

  while (current_node != 0) {

    if (current_node->get_value()->material_name == material_to_modify)
      current_node->get_value()->quantity = new_quantity;
    current_node = current_node->get_next_node();

  }
}


int City::get_material_amount(string target_material) {

  Node<Material>* current_node = first_material_node;

  while (current_node != 0) {

    if (current_node->get_value()->material_name == target_material)
      return current_node->get_value()->quantity;

    current_node = current_node->get_next_node();

  }

  return 0;

}


string City::materials_data_to_string() {

  string materials;

  Node<Material>* current_node = first_material_node;

  while (current_node != 0) {

    materials = materials + current_node->get_value()->material_name;
    materials = materials + " ";
    materials = materials + to_string(current_node->get_value()->quantity);
    materials = materials + "\n";

    current_node = current_node->get_next_node();
  }

  return materials;

}


void City::clear_material_list() {

  Node<Material>* aux_node = 0;

  while (first_material_node != 0) {

    aux_node = first_material_node;
    first_material_node = first_material_node->get_next_node();
    delete aux_node->get_value();
    delete aux_node;

  }

}


//-----------------------------Building Management------------------------------

void City::add_building(string building_type, int amount_to_build,
                          bool loading_from_txt){

  string lowercase_building_type = lowercase_word(building_type);

  string capitalized_building_type = lowercase_building_type;
  capitalized_building_type[0] = toupper(capitalized_building_type[0]);

  //checks if the type is valid
  bool valid_type = validate_building_type(lowercase_building_type);

  //checks if the number of buildings does not exceed the maximum number allowed
  bool valid_amount = false;

  if (valid_type) {
    valid_amount = validate_building_amount(lowercase_building_type, amount_to_build);
  }

  //This is for the console to print the right error message, in the if statement below
  else {
    valid_amount = true;
  }

  //checks if user has enough materials to build
  bool enough_materials = false;

  if (!loading_from_txt && valid_type && valid_amount) {

    enough_materials = validate_material_requirement(lowercase_building_type);

    if(enough_materials){

      int amount_of_stone = get_material_amount("piedra");
      int amount_of_wood = get_material_amount("madera");
      int amount_of_steel = get_material_amount("metal");

      for (int i = 0; i < record_capacity; i++) {

        if(record[i].building_type == lowercase_building_type){

          set_material_amount("piedra", amount_of_stone - record[i].stone_cost);
          set_material_amount("madera", amount_of_stone - record[i].wood_cost);
          set_material_amount("metal", amount_of_stone - record[i].steel_cost);

        }

      }

    }

  }

  else {
    enough_materials = true;
  }

  if (valid_type && valid_amount && enough_materials) {

    if(!loading_from_txt){

      string user_confirmation;

      std::cout << "Are you sure you want to add a building: " << BOLD_GREEN
                  << capitalized_building_type << DEFAULT_COLOR << " (y/n): ";

      std::cin >> user_confirmation;


      if (user_confirmation == "y" || user_confirmation == "yes") {

        for (int i = 0; i < amount_to_build; i++) {

          Building* new_building = new Building(lowercase_building_type);
          Node<Building>* new_node = new Node<Building>(new_building);
          new_node->set_next_node(first_building_node);
          first_building_node = new_node;

        }

        std::cout << BOLD_GREEN<< "Building: " << capitalized_building_type
                    << ", successfully built." << DEFAULT_COLOR << '\n';

      }


      else {
        std::cout << BOLD_RED << "ERROR:" << DEFAULT_COLOR << " Building: "
                    << BOLD_GREEN << capitalized_building_type << DEFAULT_COLOR
                      << "wasn't successfully constucted "<< '\n';
      }

    }

    else { //this is for loading buildings from the txt file

      for (int i = 0; i < amount_to_build; i++) {

        Building* new_building = new Building(lowercase_building_type);
        Node<Building>* new_node = new Node<Building>(new_building);
        new_node->set_next_node(first_building_node);
        first_building_node = new_node;

      }

    }

  }

  else if (!valid_type && valid_amount && enough_materials) {
    std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR <<
                 "Invalid building type: " << capitalized_building_type <<
                  ", check menu option '4' to see all valid types." << '\n';
  }


  else if (valid_type && !valid_amount && enough_materials) {
  std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR << "Building type: " <<
                capitalized_building_type << " surpasses max quantity allow,"
                " check menu option '3' to see amount built." << '\n';
  }

  //guess i could use just an else but i think is clearer this way
  else if (valid_type && valid_amount && !enough_materials) {
    std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR <<
                  "You don't have enough materials to build building: " <<
                    capitalized_building_type << ", check menu option '1' and '4' to see "
                     "materials amount and building costs." << '\n';
  }
}


void City::demolish_building(string building_type) {

  string lowercase_building_type = lowercase_word(building_type);

  string capitalized_building_type = lowercase_building_type;
  capitalized_building_type[0] = toupper(capitalized_building_type[0]);

  bool building_demolished = false;

  //You can do this with just current node and check for the next node to
  //that one, but i think is easier to read with 2 pointers.
  Node<Building>* current_node = first_building_node;
  Node<Building>* previous_node = 0;

  //Building to demolish is in the first node
  if (first_building_node->get_value()->get_type() == lowercase_building_type) {

    int amount_of_stone = get_material_amount("piedra");
    int amount_of_wood = get_material_amount("madera");
    int amount_of_steel = get_material_amount("metal");

    for (int i = 0; i < record_capacity; i++) {

      if (record[i].building_type == lowercase_building_type) {

        set_material_amount("piedra", amount_of_stone + record[i].stone_cost / 2);
        set_material_amount("madera", amount_of_wood + record[i].wood_cost / 2);
        set_material_amount("metal", amount_of_steel + record[i].steel_cost / 2);

      }
    }

    first_building_node = first_building_node->get_next_node();

    delete current_node->get_value();
    delete current_node;

    building_demolished = true;
  }

  while (current_node != 0 && building_demolished == false) {

    if (current_node->get_value()->get_type() == lowercase_building_type) {

      int amount_of_stone = get_material_amount("piedra");
      int amount_of_wood = get_material_amount("madera");
      int amount_of_steel = get_material_amount("metal");

      for (int i = 0; i < record_capacity; i++) {

        if (record[i].building_type == lowercase_building_type) {

          set_material_amount("piedra", amount_of_stone + record[i].stone_cost / 2);
          set_material_amount("madera", amount_of_wood + record[i].wood_cost / 2);
          set_material_amount("metal", amount_of_steel + record[i].steel_cost / 2);

        }
      }

      previous_node->set_next_node(current_node->get_next_node());

      delete current_node->get_value();
      delete current_node;

      current_node = 0;
      building_demolished = true;
    }

    else {
      previous_node = current_node;
      current_node = current_node->get_next_node();
    }

  }

  if (building_demolished)
    std::cout << BOLD_GREEN << "Building: '" << capitalized_building_type <<
                            "' successfully demolish." << DEFAULT_COLOR << '\n';

  else
    std::cout << BOLD_RED << "ERROR: " << DEFAULT_COLOR << "Building: '"
               <<capitalized_building_type << "' not founded. "
                << "Check option 3 to see all built buildings"<< '\n';
}


void City::show_buildings() {

  system (CLR_SCREEN);

  int type_amount = 0;
  Node<Building>* current_node = first_building_node;

  //when it's done looping through the linked list, it switches to the next
  //building type and loops through the list again
  for(int i = 0; i < record_capacity; i++){

    string type_being_counted = record[i].building_type;

    string capitalized_building_type = type_being_counted;
    capitalized_building_type[0] = toupper(capitalized_building_type[0]);

    while (current_node != 0 && record[i].max_quantity != 0) {

      if (current_node->get_value()->get_type() == type_being_counted)
        type_amount++;

      current_node = current_node->get_next_node();
  }

    if (record[i].max_quantity != 0)
      std::cout << left << setw(WIDTH) << "Amount of: " << BOLD_GREEN
        << setw(WIDTH) << capitalized_building_type << DEFAULT_COLOR <<
         setw(WIDTH) << " is: " << BOLD_BLUE << type_amount << DEFAULT_COLOR << '\n';


    type_amount = 0;
    current_node = first_building_node;
  }
}


//-------------------------Private Buildings methods----------------------------

int City::get_building_quantity (string type_being_counted) {

  int type_amount = 0;

  Node<Building>* current_node = first_building_node;

  while (current_node != 0) {

    if (current_node->get_value()->get_type() == type_being_counted)
      type_amount++;

    current_node = current_node->get_next_node();
  }

  return type_amount;

}


void City::clear_building_list() {

  Node<Building>* aux_node = 0;
  while (first_building_node != 0) {

    aux_node = first_building_node;
    first_building_node = first_building_node->get_next_node();

    //deletes the building and the deletes the node.
    delete aux_node->get_value();
    delete aux_node;

  }
}


bool City::validate_building_type(string building_type){

  bool valid_type = false;

  int i = 0;

  while (!valid_type && i < record_capacity) {

    if (record[i].building_type == building_type)
      valid_type = true;

    i++;
  }

  return valid_type;

}


bool City::validate_building_amount(string building_type, int amount_to_build){

  bool valid_amount = false;

  int buildings_built = get_building_quantity(building_type);
  int i = 0;

  while (!valid_amount && i < record_capacity) {

    if (record[i].building_type == building_type
        && amount_to_build + buildings_built <= record[i].max_quantity)
      valid_amount = true;

    i++;
  }

  return valid_amount;

}


bool City::validate_material_requirement(string building_type){

  bool enough_materials = false;

  for (int i = 0; i < record_capacity; i++) {

    if (record[i].building_type == building_type
        && record[i].stone_cost <= get_material_amount("piedra")
        && record[i].wood_cost <= get_material_amount("madera")
        && record[i].steel_cost <= get_material_amount("metal"))
        {

          enough_materials = true;
    }

  }

  return enough_materials;

}

//-----------------------------Record Management--------------------------------

void City::add_building(string type, int stone_cost, int wood_cost,
                        int steel_cost, int max_building_quantity){

  if (this->full_record()) {
    this->record_capacity += 5;
    Building_record* new_record = new Building_record[record_capacity];

    for (int i = 0; i < record_capacity - 5; i++) {
      new_record[i] = record[i];
    }

  //i create this auxilar array just so i don't lose the original array on record
  Building_record* aux_record = record;
  record = new_record;
  delete[] aux_record;

  }

  struct Building_record new_bulding{lowercase_word(type),stone_cost, wood_cost, steel_cost, max_building_quantity};
  record[current_position] = new_bulding;
  current_position++;

}


void City::show_record() {

    system (CLR_SCREEN);

  std::cout << "All the types of buildings are:" << '\n';

  std::cout << "(Names in "<< BOLD_GREEN << "green" << DEFAULT_COLOR
             << " are buildings you can build, " << BOLD_RED << "red"
              << DEFAULT_COLOR << " are the one you can't)" << '\n' << '\n';

  bool enough_materials = false;
  bool valid_amount = false;

  for (int i = 0; i < record_capacity; i++) {

    if (record[i].building_type != "") {

      string capitalized_building_type = record[i].building_type;
      capitalized_building_type[0] = toupper(capitalized_building_type[0]);

      enough_materials = validate_material_requirement(record[i].building_type);
      valid_amount = validate_building_amount(record[i].building_type, 1);

      if (enough_materials && valid_amount)
        std::cout << "Building type:         " << BOLD_GREEN << capitalized_building_type << '\n';

      else
        std::cout << "Building type:         " << BOLD_RED << capitalized_building_type << '\n';

      std::cout << DEFAULT_COLOR << "Stone cost:            " << BOLD_BLACK  << record[i].stone_cost << '\n';
      std::cout << DEFAULT_COLOR << "Wood cost:             " << BOLD_GREEN << record[i].wood_cost << '\n';
      std::cout << DEFAULT_COLOR << "Steel cost:            " << BOLD_CYAN  << record[i].steel_cost << '\n';
      std::cout << DEFAULT_COLOR << "Amount of buildigns:   " << BOLD_BLUE  << get_building_quantity(record[i].building_type) << '\n';
      std::cout << DEFAULT_COLOR << "Amount allow to build: " << BOLD_RED << record[i].max_quantity - get_building_quantity(record[i].building_type) << '\n';
      std::cout << "\n" << BOLD_VIOLET << DIVISORY_LINE << DEFAULT_COLOR << "\n" << "\n";

    }

  }

  std::cout << "Remember your current materials are: " << '\n';
  show_materials();

}


string City::building_data_to_string() {

  string building_data;

  for(int i = 0; i < record_capacity; i++) {

    if (record[i].building_type != "") {

      building_data = building_data + record[i].building_type + " ";
      building_data = building_data + to_string(record[i].stone_cost) + " ";
      building_data = building_data + to_string(record[i].wood_cost) + " ";
      building_data = building_data + to_string(record[i].steel_cost) + " ";
      building_data = building_data + to_string(get_building_quantity(record[i].building_type)) + " ";
      building_data = building_data + to_string(record[i].max_quantity) + "\n";

    }

  }

  return building_data;

}


//---------------------------Private Record methods-----------------------------

bool City::full_record() {
  return current_position == record_capacity;
}

//---------------------------Private Naming methods-----------------------------

string City::lowercase_word(string word){

    for (unsigned int i = 0; i < word.length(); i++) {

        word[i] = (char)tolower(word[i]);

    }

    return word;
}

//------------------------------------------------------------------------------

City::~City() {

  clear_building_list();
  clear_material_list();
  delete[] record;
  record = 0;

}
