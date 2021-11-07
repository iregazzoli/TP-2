#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <iostream>
#include <fstream>
#include "city.h"

using namespace std;

bool load_materials(City* city);

bool load_buildings_attributes(City* city);

bool load_buildings(City* city);

bool load_tiles(City* city);

#endif
