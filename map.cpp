#include "map.h"
#include "constants.h"

Map::Map(int rows, int columns){

  Tile*** map = new Tile**[rows];

  for(int i = 0; i < rows; i++)
    map[i] = new Tile*[columns];

  initialize(rows, columns);
  current_tile = map[0][0];

}

void Map::initialize(int rows, int columns){

  for(int i = 0; i < rows; i++){

    for(int j = 0; j < columns; j++){
      map[i][j] = 0;
    }

  }

}

void Map::add_tile(string tile_type){

  if(tile_type == LAKE)
    current_tile = new Inaccesible_tile;

  else if(tile_type == TERRAIN)
    current_tile = new Buildable_tile;

  else
    current_tile = new Passable_tile;

}
