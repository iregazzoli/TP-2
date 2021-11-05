#include "factory.h"

Factory::Factory(string building_type, int x_coordinate, int y_coordinate) :
          Building(building_type, x_coordinate, y_coordinate) {}

int Factory::quantity_provides_materials() {

    return STEELPROVIDED_BY_FACTORY;

}
