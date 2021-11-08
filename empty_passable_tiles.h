#ifndef EMPTY_PASSABLE_TILES_H
#define EMPTY_PASSABLE_TILES_H

#include "list.h"
#include <stdlib.h>
#include <time.h>

struct EmptyTile {

  int x_coordinate = 0;
  int y_coordinate = 0;

};

class EmptyPassableTiles{

private:
  List<EmptyTile>* passable_tiles;
  int total_of_tiles;

public:

  EmptyPassableTiles();
  
  ~EmptyPassableTiles();

  void add_empty_tile(int x_coordinate, int y_coordinate);

  void get_random_tile();

  int get_target_tile_x_coordinate();
  int get_target_tile_y_coordinate();

  void delete_target_tile();

};

#endif
