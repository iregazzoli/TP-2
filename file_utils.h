#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <iostream>
#include <fstream>
#include "city.h"

using namespace std;

//PRE: 'city' must be correctly created.
//POS: Returns true if the MATERIAL_FILE_ROUTE could be opened, false if not
bool load_materials(City* city);

//PRE: 'city' must be correctly created.
//POS: Returns true if the BUILDING_FILE_ROUTE could be opened, false if not
bool load_buildings_attributes(City* city);

//PRE: 'city' must be correctly created.
//POS: Returns true if the MAP_LOCATIONS_ROUTE could be opened, false if not
bool load_buildings(City* city);

//PRE: 'city' must be correctly created.
//POS: Returns true if the MAP_FILE_ROUTE could be opened, false if not
bool load_tiles(City* city);

#endif //FILE_UTILS_H
