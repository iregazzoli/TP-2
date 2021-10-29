#include "map.h"
#include "constants.h"

Map::Map(int rows, int columns){

  total_of_rows = rows;
  total_of_columns = columns;

  Tile*** map = new Tile**[rows];

  for(int i = 0; i < rows; i++)
    map[i] = new Tile*[columns];

  initialize();

  current_row = 0;
  current_column = 0;
  current_tile = map[current_row][current_column];

}

void Map::initialize(){

  for(int i = 0; i < total_of_rows; i++){
    for(int j = 0; j < total_of_columns; j++){
      std::cout << "i = "  << i << ", j = " << j << '\n';
      map[i][j] = 0; //breaks here on the second loop (i = 1)
      std::cout << "casillero apunta a: " << map[i][j] << '\n';
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


  if(current_column == total_of_columns - 1) {

    current_column = 0;
    current_row++;

  }

  else
    current_column++;

  current_tile = map[current_row][current_column];

}

void Map::consult(int x_coordinate, int y_coordinate){

  current_tile->show();

}
