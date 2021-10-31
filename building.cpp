#include "building.h"

Building::Building(string building_type, int x_coordinate, int y_coordinate){

  this->building_type = building_type;
  this->x_coordinate = x_coordinate;
  this->y_coordinate = y_coordinate;

}

void Building::set_type(string new_type){

  building_type = new_type;

}

string Building::get_type(){

  return building_type;

}



void Building::set_x_coordinates(int new_x_coordinate){

  x_coordinate = new_x_coordinate;

}

int Building::get_x_coordinates(){

  return x_coordinate;

}

void Building::set_y_coordinates(int new_y_coordinate){

    y_coordinate = new_y_coordinate;

}


int Building::get_y_coordinates(){

  return y_coordinate;

}
