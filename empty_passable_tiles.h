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

  //PRE:-
  //POS: Creates a EmptyPassableTiles object, a list of EmptyTile with it's liked list pointers pointing to null 
  //     and initializes total_of_tiles = 0.
  EmptyPassableTiles();

  //PRE:-
  //POS: Destroys EmptyPassableTiles object and frees memory from linked list.
  ~EmptyPassableTiles();

  //PRE:-
  //POS: Creates a new EmptyTile, adds it to the list and increase total_of_tiles.
  void add_empty_tile(int x_coordinate, int y_coordinate);

  //PRE:-
  //POS: Returns true if the list is empty.
  bool not_empty_tiles();

  //PRE:-
  //POS: Picks randomly a tile.
  bool select_random_tile();

  //PRE:-
  //POS: Returns x coordinate of tile
  int get_target_tile_x_coordinate();

  //PRE:-
  //POS: Returns y coordinate of tile
  int get_target_tile_y_coordinate();

  //PRE:-
  //POS: Removes tile from the list and decrement 'total_of_tiles'.
  void delete_target_tile();

};

#endif //EMPTY_PASSABLE_TILES_H
