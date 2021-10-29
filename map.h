#ifndef MAP_H
#define MAP_H
#include "tile.h"
#include "buildable_tile.h"
#include "passable_tile.h"
#include "inaccesible_tile.h"


class Map {

private:
  Tile*** map;
  Tile* current_tile;

public:
  Map(int rows, int columns);
  void initialize(int rows, int columns);
  void add_tile(string tile_type);

};


#endif
