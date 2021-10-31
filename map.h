#ifndef MAP_H
#define MAP_H
#include "tile.h"
#include "buildable_tile.h"
#include "passable_tile.h"
#include "inaccesible_tile.h"


class Map {

private:
  Tile*** map;

  int total_of_rows;
  int total_of_columns;

  Tile** current_tile;
  int current_row;
  int current_column;

public:
  Map(int rows, int columns);
  void initialize();

  //PRE: (maybe clarify that the amount on letters on the, nah don't bother)
  //POS:
  void add_tile(char tile_type);
  void consult(int x_coordinate, int y_coordinate);

};


#endif
