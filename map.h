#ifndef MAP_H
#define MAP_H
#include "tile.h"
#include "buildable_tile.h"
#include "building.h"
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
  
  //PRE: 'row' >= 0. 'columns' >= 0
  //POS: Assigns total_of_rows = 'rows', total_of_columns = 'columns', current_row = 0, current_column = 0. 
  //     Creates a dynamic matrix of dimension (total_of_rows x total_of_columns) and initializes null. 
  Map(int rows, int columns);

  //PRE:-
  //POS: Destroy map and free dynamic matrix memory.
  ~Map();

  //PRE: 'tile_type' must be LAKE, TERRAIN or ROAD.
  //POS: Loads the map with the tiles types. Creates InaccesibleTile, BuildableTile or PassableTile objects, as appropriate.
  void add_tile(char tile_type);

  //PRE: x_coordinate' and 'y_coordinate' must be valid map coordinates.
  //POS: Shows on screen the tile type and if its empty or the content.
  void consult(int x_coordinate, int y_coordinate);

  //PRE: x_coordinate' and 'y_coordinate' must be the coordinates of buildable tile.
  //POS: Returns the building type.
  string get_building_type(int x_coordinate, int y_coordinate);

  //PRE: x_coordinate' and 'y_coordinate' must be valid map coordinates.
  //POS: Returns the pointer found at those coordinates.
  Tile* get_tile(int x_coordinate, int y_coordinate);

  //PRE: x_coordinate' and 'y_coordinate' must be valid map coordinates.
  //POS: Returns true if a buildable tile is found in those coordinates.
  bool tile_buildable(int x_coordinate, int y_coordinate);

  //PRE: x_coordinate' and 'y_coordinate' must be valid map coordinates.
  //POS: Returns true if a passable tile is found in those coordinates.
  bool tile_passable(int x_coordinate, int y_coordinate);

  //PRE: x_coordinate' and 'y_coordinate' must be valid map coordinates.
  //POS: Returns true if tile is empty.
  bool tile_empty(int x_coordinate, int y_coordinate);

  //PRE: x_coordinate' and 'y_coordinate' must be the coordinates of buildable tile.
  //POS: Creates a new Building and saves it at those coordinates.
  void add_building(Building* building, int x_coordinate, int y_coordinate);

  //PRE: x_coordinate' and 'y_coordinate' must be the coordinates of buildable tile.
  //POS: The pointer that was pointing to the Building object now points to null.
  void remove_building(int x_coordinate, int y_coordinate);

  //PRE: x_coordinate' and 'y_coordinate' must be the coordinates of passable tile.
  //POS: Creates a new Material and saves it at those coordinates.
  void add_material(Material* material, int x_coordinate, int y_coordinate);

  //PRE:-
  //POS: Returns total_of_rows.
  int get_rows();

  //PRE:-
  //POS: Returns total_of_columns.
  int get_columns();

  //PRE:-
  //POS: Shows on screen the map with icons representing buildings, materials and  tiles types. 
  void show_map();


private:

  //PRE:-
  //POS: Initializes the dynamic matrix with 0.
  void initialize();

  //PRE:-
  //POS: Shows on screen  map references.
  void show_map_legend();

};


#endif //MAP_H
