#include "mine.h"

Mine::Mine(string building_type, int x_coordinate, int y_coordinate) :
          Building(building_type, x_coordinate, y_coordinate) {}

int Mine::quantity_provides_materials() {

    return STONE_PROVIDED_BY_MINE;
}
