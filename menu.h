#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <fstream>
#include "city.h"
#include "building.h"

using namespace std;

class Menu {

public:

  //PRE:-
  //POS:
  void show_menu();

  //PRE:-
  //POS:
  void how_do_you_turn_this_on();

  //PRE:-
  //POS:
  void press_enter_to_continue();

  //PRE:-
  //POS:
  void build(City* city);

  //PRE:-
  //POS:
  void demolish(City* city);

  void save_data(City* city);

  bool interpretate_user_input(City* city);

  int ask_user_x_coordinate(City* city);

  int ask_user_y_coordinate(City* city);


};


#endif //MENU_H
