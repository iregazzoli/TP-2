#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <fstream>
#include "city.h"
#include "building.h"
#include <cctype>
#include <cstring>

using namespace std;

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

void show_menu() {

  std::cout << '\n';
  std::cout << "Welcome to " << BOLD_GREEN << "Andypolis Construction Menu"
                                  << DEFAULT_COLOR << ", options are: " << '\n';

  std::cout << BOLD_YELLOW << "[1]" << DEFAULT_COLOR << " List construction materials. ('1' or 'materials')" << '\n';
  std::cout << BOLD_YELLOW << "[2]" << DEFAULT_COLOR << " Build building by name. ('2' or 'build')" << '\n';
  std::cout << BOLD_YELLOW << "[3]" << DEFAULT_COLOR << " List the buildings built. ('3' or 'buildings')" << '\n';
  std::cout << BOLD_YELLOW << "[4]" << DEFAULT_COLOR << " List all buildings. ('4' or 'record')" << '\n';
  std::cout << BOLD_YELLOW << "[5]" << DEFAULT_COLOR << " Demolish a building by name. ('5' or 'demolish')" << '\n';
  std::cout << BOLD_YELLOW << "[6]" << DEFAULT_COLOR << " How do you turn this on. ('6' or 'how_do_you_turn_this_on')" << '\n';
  std::cout << BOLD_YELLOW << "[7]" << DEFAULT_COLOR << " Save and exit. ('7' or 'exit')" << '\n';
  return;

}

void how_do_you_turn_this_on() {

  system (CLR_SCREEN);
  string problematic_line_1_part_1 = R"(/`-')";
  string problematic_line_1_part_2 = R"(( )         ( ))";
  string problematic_line_1_part_3 = R"( /`-'\)";

  string problematic_line_2_part_1 = R"(|   |)";
  string problematic_line_2_part_2 = R"(---\_Cobra_/---)";
  string problematic_line_2_part_3 = R"(|   |)";

  std::cout << '\n';
  std::cout << "                  BRRRRRRRRRRRRRRRRRRRRRR" << '\n';
  std::cout << "        _________" << '\n';
  std::cout << "       |         |" << '\n';
  std::cout << BOLD_BLUE << " _o_  _";
  std::cout << DEFAULT_COLOR << "| " << BOLD_BLUE << "___=___" << DEFAULT_COLOR <<" |";
  std::cout << BOLD_BLUE << "_  _o_" << '\n';
  std::cout << problematic_line_1_part_1;
  std::cout << DEFAULT_COLOR << problematic_line_1_part_2;
  std::cout << BOLD_BLUE << problematic_line_1_part_3 << '\n';
  std::cout << BOLD_BLACK << "|   |-"<< BOLD_BLUE << "| ";
  std::cout << DEFAULT_COLOR << " ___*___ ";
  std::cout << BOLD_BLUE << " |" << BOLD_BLACK << "-|   |" << '\n';
  std::cout << "|   |" << BOLD_BLUE << " | ";
  std::cout << BOLD_BLACK << "(-+-+-+-)";
  std::cout << BOLD_BLUE << " |" << BOLD_BLACK <<" |   |" << '\n';
  std::cout << problematic_line_2_part_1;
  std::cout << DEFAULT_COLOR << problematic_line_2_part_2;
  std::cout << BOLD_BLACK << problematic_line_2_part_3 << '\n';
  std::cout << BOLD_BLACK << " ---                 ---" << DEFAULT_COLOR << '\n';

}

void press_enter_to_continue() {

  int user_input;

  std::cout << '\n';
  std::cout << "Press ENTER to go back to the menu: ";

  do user_input = getchar(); while ((user_input != '\n') && (user_input != EOF));
}


void build(City* city) {

  system (CLR_SCREEN);
  string building_to_add;
  std::cout << "Enter the type of building you wish to build: ";
  std::cin >> building_to_add;
  city->add_building(building_to_add, 1, false);

}

void demolish(City* city) {

  system (CLR_SCREEN);
  string building_to_demolish;
  std::cout << "Enter the type of building you wish to demolish: ";
  std::cin >> building_to_demolish;
  city->demolish_building(building_to_demolish);

}

#endif
