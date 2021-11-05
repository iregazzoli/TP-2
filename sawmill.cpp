#include "sawmill.h"

Sawmill::Sawmill(string building_type, int x_coordinate, int y_coordinate) :
          Building(building_type, x_coordinate, y_coordinate) {}

int Sawmill::quantity_provides_materials() {

    return WOOD_PROVIDED_BY_SAWMILL;
}
