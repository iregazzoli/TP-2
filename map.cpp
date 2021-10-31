#include "map.h"
#include "constants.h"

Map::Map(int rows, int columns){

  total_of_rows = rows;
  total_of_columns = columns;

  std::cout << "rows: " << total_of_rows << " columns: " << total_of_columns << '\n';

  map = new Tile**[rows];

  for(int i = 0; i < rows; i++)
    map[i] = new Tile*[columns];

  initialize();

  current_row = 0;
  current_column = 0;
  current_tile = &map[current_row][current_column];

}

void Map::initialize(){

  for(int i = 0; i < total_of_rows; i++){

    for(int j = 0; j < total_of_columns; j++){

      map[i][j] = 0;

    }

  }

}

void Map::add_tile(char tile_type){

  if(tile_type == LAKE)
    *current_tile = new InaccesibleTile;

  else if(tile_type == TERRAIN)
    *current_tile = new BuildableTile;

  else
    *current_tile = new PassableTile;


  if(current_column == total_of_columns - 1) {

    current_column = 0;
    current_row++;

  }

  else
    current_column++;

  current_tile = &map[current_row][current_column];

}

void Map::consult(int x_coordinate, int y_coordinate){

  map[x_coordinate][y_coordinate]->show();

}