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
  //POS: Shows on screen options menu. 
  void show_menu();

  //PRE: City must be a non-null pointer.
  //POS: Returns false if the user decides to exit and save, and true if they continue playing.
  bool interpretate_user_input(City* city);

private:

  //PRE:-
  //POS: Shows on screen 
  void how_do_you_turn_this_on();

  //PRE:-
  //POS: Asks the user to press enter to return to the menu.
  void press_enter_to_continue();

  //PRE: City must be a non-null pointer.
  //POS: Asks user for type of building and coordinates where he wants to build it and builds it.
  void build(City* city);

  //PRE: City must be a non-null pointer.
  //POS: Asks user for coordinates of the building he wants to demolish and destroys it.
  void demolish(City* city);

  //PRE: City must be a non-null pointer.
  //POS: Updates the files with the new information.
  void save_data(City* city);

  //PRE: City must be a non-null pointer.
  //POS: Asks user for the x coordinate and returns it.
  int ask_user_x_coordinate(City* city);

  //PRE: City must be a non-null pointer.
  //POS: Asks user for the y coordinate and returns it.
  int ask_user_y_coordinate(City* city);


};


#endif //MENU_H
